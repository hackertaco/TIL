# 23/01/02
한줄 평:

Rank(top-k)조인 쿼리는 최신 분석 업무에 중요한 역할을 하지만, 간과되곤 한다.
따라서 이 간극을 좁혀보고자 한다: 전체적으로 퍼포먼스를 연구하는 것이다.

첫째로 맵 리듀스나 조정 전략을 사용해 접근될 전문적인 색인에 기반하여 솔루션을 제시한다. 

둘째로, 중앙집중된 랭크 조인 알고리즘을 접목시킨다.

조금 더 나아가 신기한 통계적 구조를 공헌한다. 

- 제공하는 것
  - 어떻게 이 색인과 통계 구조를 지을지 보여주는 맵리듀스
  - 이 색인을 온라인 업데이트 허용 알고리즘
  - 그를 이용하는 쿼리 프로세싱 알고리즘 
모든 하둡의 알고리즘을 시행했고, TPC-H 데이터셋에서 그들을 실험했다. 

## Introduction
클라우스 스토어는 매우 다양한 빅데이터 제공자, 소비자 등의 선택을 받게 되었다. 
기존의 RDBMS는 아무래도 스케일을 크게 할 수가 없어, NoSQL, MapReduce 프레임워크 기술이 생겼다.

이 기술들은 상당한 수의 서버를 스케일링하고, 장애를 견딜 수 있고, 높은 write 이용률과 낮은 read 지연을 위해 만들어졌다.

이 NoSQL DB는 key-value 모델로 보여질 수 있는데, 네개의 코어 추상화로 이루어져있다.
1) key-value pair: key, 컬럼명, 컬럼 값, 타임스탬프
2) table: key-value pairs의 정리된 컬렉션
3) row: 모든 주어진 컬렉션. 같은 키를 공유한다.
더 나아가 몇몇은 컬럼 family라는 개념도 추가한다. 이는 본질적으로 특정 컬럼명에 key-value 짝을 포함하게끔 테이블 데이터를 수직으로 나누는 개념이다.

이러한 모든 시스템은 효율적인 쿼리와 순차적인 스캔이 필요하지만, 비용이 든다. 

처음의 의도에도 불구하고, NoSQL은 재세례 받았다. "SQL 뿐만 아니라"로.
더 많은 데이터가 이 시스템에 들어올 때마다, 더 복잡한 쿼리에 대한 니즈가 생겼다. 
이는 점점 비정규화에 대한 단점 실현으로 갔다. 

NoSQL이 빠른 keyed-row 회수를 보장하지만, 이 행들은 대부분의 쿼리에서 필요없는 데이를 포함했고, 좋지않은 쿼리 성능을 보였다.
따라서, NoSQL은 몇몇 테이블을 포함하도록 변경되었으며, 외래키와 비슷한 구조로 연결되고, 쿼리 시간에 조인되었다. 
문제는 애플리케이션에 이를 처리하는 일이다. 

#### 동기
조인은 자원이 매우 부족하기 때문에, 최근의 연구는 그를 클라우드에서 사용하려고 했다.
지금까지, 랭크된 조인은 완전히 이 세팅에서 간과되었다. 이 쿼리가 다양한 상황에서 나온다는 사실에도 불구하고. 

### 문제 형성
무공유 분산 클라우드 스토어에서 작업을 한다고 가정해본다.
파일 시스템 혹은 NoSQL 어디든 테이블이 저장되어있다. 

각 행을 점수내는 것은 미리 설정된 함수나 명확한 점수 속성이다. 
우리는 이 점수 속성이 0에서 1 사이에 잇다고 가정한다. 그는 확실해야한다. 

그 다음에, 이 점수들은 f()에 의하여 계산된다.
순수하게는 조인 결과를 처음에 계산하고, 그를 랭킹하고 상위 몇개의 튜플을 선택하는 것이지만, 이는 극단적으로 비싸다.
네트워크를 이동한다고 생각했을 때, 풀 조인 을 하지않고 결과 셋을 만드는 것이 중요하다. 

### 공헌
NoSQL에서 top-k 조인쿼리를 효율적으로 하는 법은 몹시 부족하다. 
우리는 Hive나 pig를 기본 베이스라인 기술로 상정하고, 병렬방법으로 쿼리를 실행할 것이다.
그러나, 그들의 단점을 인정하여 우리는다양한 다른 접근을 연구한다. 

첫째로, 맵리듀스 솔루션을 공헌한다.
둘째로, no-맵리듀스에서, Inverse Score List Rank Join이라는 알고리즘을 만들었다. 
셋째로, Bloom Filter Histogram Matrix라는 랭크 조인 통계접근 구조를 만들었다.

우리는 이 세번째 알고리즘이 100% recall을 달성했다는 걸 증명한다. 

더 나아가, 우리는 업데이트 상황에서 색인을 효율적으로 유지하는 알고리즘을 제안한다. 

측정영역은: 쿼리 프로세싱 시간, 네트워크 대역폭, 쿼리 프로세싱 비용

## 관련 연구
1. 랭크 쿼리
   - 잘 알려져 있는 랭킹 연산자는 top-k, kNN이다. 
   - top-k 연산자는 전형적으로 레코드 세트를 수용한다. 하나의 집계 함수, 그리고 k, ID를 만들어낸다.
   - kNN은 좀 다르다. 테이블을 레코드로 받고, 유사성 개념을 만들어낸다. 
   - 이 논문은 top-k에 집중한다. 
2. 랭크와 조인 쿼리
   - kNN 조인은 랭크와 조인 연산자를 모두 가지고 있다. 
   - 점수 속성을 집계하여 나온 결과를 연산하므로 top-k와는 다르다. 
3. 클라우드에서의 조인 쿼리
   - 최근 클라우드 조인쿼리는 각광을 받고있고, 맵리듀스를 이용하여 Hive, Pig가 조인을 지원한다.
   - 하둡은 NoSQL 시스템과는 다르게, 병렬적인 DBMS다.
   - 트로이목마 색인을 도입, 데이터 로드 타임에 만들어지고 각각의 매퍼에 의해 배치된다.
   - 이 매퍼들은 값비싼 디스크 스캔을 피하고, 릴레이션을 나눈다. 
4. 블룸 필터, 조인, top-k
   - bloom 필터는 비트로 데이터를 표현하는 자료구조다. 
5. 분산 환경에서의 랭크 조인
   - 1-4는 topk 등가 조인 쿼리를 해결하지 못했다.
   

## 베이스라인 랭크 조인
두 가지의 등가 조인에 집중한다: 알고리즘을 다양한 조인으로 확장하는 것
처음으로는 Hive, Pig의 접근을 표현한다. 

### Hive, Pig의 랭크 조인
하이브에서는, 랭크조인이 두개의 맵리듀스 job과 마지막 스테이지로 이루어져있다. 
- 처음에는 일단 조인 결과를 계산, 구체화한다. 
- 두번째는 조인 결과 점수를 계산하고 그들의 점수 기반으로 정렬해서 저장한다. 
- 세번째는 그를 기반으로 k 개의 결과를 낸다.

피그는 조금 더 현명하다. 그는 프로젝션을 실시해 처음에 top-k를 찾고 조정한다. 
- 조인 결과 계산: 매퍼가 테이블 스캔, 이른 프로젝션, 키와 같은 값과 행 emit, 리듀서가 한데 모아서 조인 결과를 만들고 하둡에 저장한다. 
- 두번째는 ORDERBY 결과물이다. 조인 결과를 맵 페이즈에서 샘플링한다. 그리고 적절한 분위수를 만든다.
- 이를 통해 파티셔너를 구성하고, 임시 점수 기록, top-k생성
  - 맵할 때는 임시 레코드를 만들고, 리듀스할 때는 각각의 top-k리스트를 만든다. 이 리스트는 할당된다. 마지막 top-k 결과 셋에.

## 인덱싱된 랭크 조인

BigTable/HBase는 전형적인 키-값 클라우드 저장소여서, 그들의 용어를 알고리즘과 예제에 사용하고자한다. 
그러나 그는 명확해서 우리의 색인과 알고리즘이 모든 현재 키밸류 스토어에 적용되어야한다. 

### Inverse Join List MapReduce Rank-join
맵리듀스를 사용하지만, 요구되는 맵리듀스 잡을 한번만 하기위해 인덱스를 사용한다. 
1. Index
위의 베이스라인 조인 방법에서, 첫 단계 매퍼는 사실상 인풋 튜플 리스트를 만드는 것이었다.
사실, 항목에는 조인 값이 키로 있고 입력 행은 특정 조인 값을 값 집합으로 지정하는 구체화된 뷰다.

우리는 공간 최적화 폼을 사용한다. 인덱스 값은 행 키와 스코어 값의 곱이다. 
이 인덱스는 큰 테이블에서 각각의 열로서 저장된다.

2. 쿼리 프로세싱
- 하나의 맵리듀스 잡으로 이루어져있다. 여러개의 매퍼와 하나의 리듀서가 그것이다. 이 잡에서는, 각각의 매퍼는 인덱스를 파티셔을 통해 스캔한다. 
- 각각의 행에서, Cartesian 곱을하고 조인 점수를 계산한다. 
- 매퍼는 인메모리 top-k 랭킹 결과 튜플만을 저장한다. 
- 리듀서는 각각의 top-k 리스트를 결합하고 전역 top-k결과를 내보낸다. 
- 이는 데이터 이동을 최소화했다. 하둡 프레임워크는 각각의 매퍼가 각자 데이커를 모으며 noSQL 스토어 위에서 실행되게끔 한다. 그러므로 top-k 결과는 네트워크에 옮겨져서 리듀서에서 정렬된다. 
- 이는 하이브에 비하여 쿼리 프로세싱 시간을 훨씬 줄였고, 몇몇에서는 대역폭도 줄었다.
- 그러나, 매퍼는 여전히 전체 인품 데이터셋을 스캔해야한다. 그리고 이는 비싸다. 

## 거꾸로된 스코어 리스트 랭크 조인
분명히, 네트워크와 disk IO 대역폭을 아끼는 것은 동등하다. 또한, NoSQL 스토어의 쿼리 프로세싱 내장함수를 이용하는 것은 더 좋다. 
top-k 조인과 같은 복잡한 쿼리에는 맵리듀스가 별로 좋지는 않다. 

그래서, 먼저 HRJN을 보고, Inverse Score List rank join을 볼 것이다. 

### HRJN Overview
HRJN의 릴레이션에서, 튜플들은 리스트로서 정렬되어 릴레이션 점수 속성에 따라, 혹은 속성값에 점수 함수를 사용함으로서 나열된다.

간단히 하기 위해, 릴레이션 점수 속성을 가정하나, 우리의 솔루션은 후자와 동일하다.

조인 결과 튜플은 그 다음에 랭킹 함수로 계산된다. 랭킹함수에 의해 나온 결과들은 내림차순으로 정렬되고, 최소 최대값이 있다. 

알고리즘은 K번째 조인 결과가 한계점보다 높으면 끝난다. 

### ISL Index
HRJN처럼, ISL은 거꾸로된 점수 리스트에 기반한다. 
각각의 인풋 릴레이션에서, 인덱스를 만들고 유지하는데, 이는 컬럼 family로 구성이 되어 점수 값을 행이 key로서 가지고 있다. 그리고, 점수 속성의 인풋 튜플 값을 가지고 있다. 

꼬이는 것은 rowkey를 오름차순으로 빠르게 스캔하는데, 다른 방향은 없다는 것이다. 이것 때문에, 스코어 점수를 음수로 처리했다.

### ISL 쿼리 프로세싱
쿼리 프로세싱 중에, 중재자가 인덱스 column family를 스캔한다. 
스캔은 오름차순으로 진행된다. NoSQL스토어가 본질적으로는 컬럼 스토어이고, key-value 짝들은 디스크에서 서로 옆으로 쌓이기 때문에, disk IO 오버헤드가 낮게 나온다. 프로세싱 타임도 낮게 나온다. 
이 스캔은 쿼리 프로세싱 시간에 큰 도움이 된다. 대역폭이나 돈은 비싸다. 
 중재자는 모든 회수된 튜플들을 나눠서 조인 값을 키로 사용해,해시테이블에 저장한다. 
이는 새로운 튜플들이 생길 때마다 빠른 처리를 가능케한다. 
더불어, 중재자는 현재 top-k 결과도 유지한다. 모든 새로운 튜플들이 프로세스되면, 중재자는 현재 한계값을 계산하고 그 값이 k번째 튜플보다 낮으면 종료한다. 

## 통계적 랭크 조인
이전의 알고리즘은 top-k 결과에 없더라도 튜플을 보낸다. 

이를 피하고자 한다. 조인 결과를 어떤 튜플이 만들어낼지 예상해야하고, 이 튜플들이 top-k 점수를 가질 수 있을지 예상해야한다.

### BFHM 데이터 구조
BFHM 색인은 두 단계의 통계 자료구조다. 히스토그램과 블룸 필터를 포괄한다.

첫째로, 같은 너비의 히스토그램을 점수 axis에 올린다. 즉, 모든 히스토그램 버켓은 같은 스프레드를 가지고 버켓 경계 안에 점수가 있는 튜플 정보를 저장한다.

두번째로, 버켓에 속하는 튜플의 조인 값을 저장하며 블룸필터를 선택한다. 이는 조인 결과의 카디날리티를 예측하는데 사용될 것이다. 

BFHM 자료구조는 두개의 메인 파라미터가 있다: 하나는 BFHM의 버켓 수, 하나는 블룸필터 버켓의 비트 수다. 

거짓 양성값이 조인 카디날리티 예측을 뻥튀기 할 수 있기 때문에, 하나의 해시 함수와 카운터를 결합한다.
구체적으로, BFHM은 1) 버켓에 기록된 튜플 점수 최소, 최대값 2) 블룸필터 사이즈 해시 함수 3) 0이 아닌 블룸필터 해시테이블 카운터를 유지한다.

2, 3은 모두 Golomb 코딩을 사용하여 압축된다. Golomb Compressed Sets와 Counting Bloom filters 사이 하이브리드 자료구조가 나올 것이다. 거짓 양성을 최소화 하고, 전체적인 NoSQL 스토어에 저장된 바이트 양을 줄이고, 합리적인 비용을 달성한다. 


인덱스처럼, BFHM데이터도 NoSQL 스토어에 저장된다. 각각의 인풋 릴레이션에서, BFHM 인덱스는 분리된 컬럼 패밀리 혹은 인덱스 테이블에 저장된다. 
각각의 BFHM 버켓은 나눠진 행에 쌓이고 버켓 번호가 키가 된다. 
행 값은 최소 최대값을 포함한다. 게다가, 쿼리 프로세싱하는 동안 일치하는 조인 값으로 돌아가 BFHM 세트를 사상할 수 있어야한다. 
대부분의 quasi-random 해시 함수에서는 이것이 불가하지만, 우리는 이 매핑을 저장해야한다. 
이들은 키가 같은 버켓명과 비트 위치의 연쇄를 포함하는 컬럼 패밀리와 테이블에 저장된다. 그리고 행 데이터는 튜플 형식이 이러하다 > {rowkey : join value, score}

이는 맵리듀스 잡을 통해 만들어진다.

- 맵 단계에서, 매퍼는 다양한 히스토그램 버켓으로 들어오는 튜플들을 나눈다. 각각의 리듀서는 이 튜플에 대하여 한번에 한 버켓으로 작업한다. 
- 각각의 튜플은 조인 값에 기반하여 BFHM 하이브리드 필터에 추가되고, 따라오는 비트 포지션은 기록된다. 
- 리듀서는 그러한 튜플에서의 뒤집어진 매핑 입구를 emit하고, 최대최소값을 기록한다. 
- 버켓 튜플이 소진되면, 리듀서는 BFHM 버켓 blob 행을 emit한다.

### BFHM 쿼리 프로세싱
두 단계를 포함한다. 1) 결과를 예측 2) 진짜 결과를 거꾸로 매핑하고 계산
BFHM 버켓 행을 fetch, 조인 결과는 예측된 결과 리스트에 추가된다. 그다음에 예측 결과 리스트로 버켓에 조인 결과가 추가된다. 
이 에측된 수가 k를 넘으면, 알고리즘은 BFHM 종료 조건을 테스트한다. 
그 다음에는 reverse mapping/final result set으로 프로세싱이 이어진다. 

### BFHM 분석
랭크 조인 결과를 예측할 때 부정확한 두개의 소스를 다룬다. 하나는 히스토그램과 하나는 bloom filter다. 
전자는 조인 결과의 실제 점수를 예측하는데 있어, 후자는 거짓 양성이 나올 수 있어 둘다 에러가 날 수 잇다. 

완전히 거짓 양성을 배제할 수는 없기에, 효과적인 거짓 양성 가능성을 도입했다.  

히스토그램과 하나는 bloom filte를 통하여, 우리는 100% 리콜이라는 결과를 내었다. 

첫째로, 우리가 k 혹은 더 많은 결과를 가지게되면, k변째 실제 조인 결과 점수를 파악해서 최대값과 비교한다. 
만약, 최대값이 버켓에 존재하면, 그 추가적인 버켓도 고려한다. 

변화가 이 단계 이후에 없으면 알고리즘은 종료된다. 

## 업데이트와 유지
IJLMR, ISL은 공간 최적화 리스트다. 
이를 계속해서 정확히하기위해, 전체 데이터를 오버로드했다. 시간은 빨랐지만, 

BFHM blob는 업데이트가 더 복잡하게 만들엇다. 
이를 보완하려고 삽입과 톰스톤 자료로 업데이트를 실행했다. 
각각의 튜플은 삽입되어 버켓 행에 추가되고, 새로이 튜플이 들어올 때 타임스탬프를 유지한다. 
반대로, BFHM 버켓에서 튜플이 삭제되면, 톰스톤 자료가 버켓에 추가되고, 삭제 작업이 이뤄진다. 
