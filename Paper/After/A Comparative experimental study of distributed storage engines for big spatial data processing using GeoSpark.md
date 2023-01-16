효과적이고 효율적으로 방대한 양의 공간 데이터를 저장하고 처리하는 일은 도전을 요구한다. 
그 이유는 공간 데이터 처리에 본질적인 복잡성 때문이다. Ex. 공간 근접성에 기반을 두어, 장소를 잘 알지 않은채 파티셔닝을 했을 때, 관계없는 데이터들이 평가되고, 전반적인 쿼리 성능, 자원을 소모한다.

또한 공간 데이터 처리가 산란된 데이터 형식에서 나온 이질적인 데이터라는 점도 힘든 점이다. 

이 두 문제를 해결하기위해, 맵리듀스같은 컴퓨테이션 모델을 제공하는 프레임워크를 기반으로 한 여러 분산 시스템이 도입이되었다. 

아파치 하둡과 스파크가 그것이다. 
그 중에서도 공간 개체를 다루고, 공간 쿼리 프로세스를 지원하는 시스템이 있다. 최근 연구에서 공간 데이터 프로세싱은 잘 평가가 되었지만, 각기다른 스토리지 엔진에 대하여서는 연구된 바가 없다.

따라서, 다양한 분산 스토리지엔진을 평가한다. 많은 양의 공간데이터를 다루는 데 좋은 성능을 보이는 GeoSpark를 데이터 프로세싱 시스템으로 삼는다.
cloud 컴퓨팅 환경에서, 연구된 바는 거의 없지만 어떤 스토리지가 최고의 공간 처리에 좋은지 실험해본다.

스토리지 1:: HDFS
분산 스토리지 엔진. 원격 스토리지 시스템과 비교해서 성능 개선을 예상할 수 있다.
그 이유는 네트워크를 통한 데이터 이동을 최소화할 수 있기 때문이다. 
그러나, 실 클러스터 환경에서 그것이 가능한지 실험해야한다. 

스토리지 2:: MongoDB
자체 공간 인덱스와 쿼리 프로세싱을 제공한다. 

스토리지 3:: Amazon s3
cloud-based 개체 스토어. 대부분의 cloud providers는 s3와 같은 지속 데이터 스토리지를 제공한다. 
장애를 견딜 수 있고 확장성이 잇다는 것은 잘 알려저있지만, 큰 범위의 데이터 처리에는 균열이 있다는 자료가 있다. 
이를 HDFS와 비교해본다.

EMR 구조로 실 클라우드컴퓨팅 세팅을 한다. 
데이터 셋은 실세계에서의 분산, 다양한 데이터 사이즈로 준비했다.
변인은 몽고디비에서의 sharding strategies, 캐싱, 데이터 분산, 데이터 셋 사이즈, 스토리지 노드와 익스큐터 수, 쿼리 선택이다.

## Background
### GeoSpark
스파크 기반으로 작동하는 공간 분산 데이터 프로세싱 엔진. 
다양한 인풋 포맷 지원. 여러 지역 타입 처리 가능.(점, 선 면)
RDD라는 스파크의 기본 데이터 단위를 확장한다.

공간 개체를 공간 인접성으로 나누기 위하여, GeoSpark는 전역 지역 데이터 파티셔닝을 지원한다. 
1. GeoSpark는 임의로 RDD를 샘플링하여 인덱스를 구축한다.
2. 인덱스 leaf node를 재파티셔닝하는 데 사용한다. (넓은 영역에서의 RDD 변형)

GeoSpark는 지역적인 공간 인덱싱도 지원한다. 
샘플링된 데이터를 사용하는 전역 인덱싱과는 다르게, 지역 엔덱스 구조는 모든 개체를 기반으로 생성된다.

Spark처럼, GeoSpark도 다양한 스토리지 엔진과 함께 사용될 수 있다. 
그러나, GeoSpark와 다양항 스토리지 엔진의 결합 중 무엇이 더 좋은 결과를 낳는지에 대해서는 연구된 바가 없어, 그에 대해 평가하고자 한다.

### HDFS
- 대표적인 분산 파일 시스템.
- 전체 파일을 128MB로 나누어 복제를 한다. 
- 1개의 name node, 여러개의 data node로 구성되어있다.
- name node는 어떤 data node가 어떤 데이터 블록을 가지고 있는지에 대해 설명하는 metadata를 관리하고, 클라이언트에게 요청된 데이터를 가지고 있는 데이터 노드 리스트를 보낸다.
- data node는 전체 데이터 파일이 파티셔닝된 실 데이터 블록을 가지고 있고, 요청받은 데이터를 제공한다.
- 효율적으로 데이터 처리를 하기 위해서, 클러스터에 쌓인 데이터 분산을 고려해야한다. 
- 지역성 고려, 노드들끼리의 소통 최소화. 데이터 노드들에 정해진 임무를 부여하여서.
- 다양한 노드에 복제된 블록을 저장하여 장애를 견딜수있게 하고
- 새로이 데이터 노드가 추가되어도 데이터 블록을 재분배하여 확장성을 꾀한다.

### MongoDB
- 가장 널리 사용되는 NoSQL 스토어. 
- JSON, XML과 같은 계층적 자료를 효과적으로 쌓는다. 
  - RDBMS와는 다르게, 엄격한 스키마를 요하지 않는다. 
- 전체 데이터를 저장할 때, 어떻게 데이터를 파티션할지를 고려해야한다. 
- MongoDB는 1) Config 2) Router 3) Shard Server로 구성돼있다. 
  - config server는 어떤 데이터 샤드가 어떤 샤드 서버에 저장될지에 대한 메타데이터를 관리한다. 
  - router server는 config server에 저장된 메타데이터를 기반으로 클라이언트 요청을 샤드 서버로 라우팅한다.
  - 각각의 샤드 서버는 데이터가 파티션되고 복제되어있는 데이터 샤드를 가지고있다. 
    - 이 샤드 전략에는 두개가 있다. 하나는 hash-based, 다른 하나는 range-based다.
    - 이 논문에서는 공간 데이터의 인접성을 고려해야하므로, random sharding과 공간 인접성에 따른 sharding을 평가할 겻이다.
- 공간 쿼리 프로세싱을 제공한다. 
- 커넥터로 스파크와 연결한다. 
  - 이를 통해 몽고디비의 데이터를 읽을 수 있고, 스파크는 데이터를 쓸 수 있다.
  - 집계 파이프라인도 지원하여, 데이터 필터를 한다. 

### Amazon S3
- cloud-based storage engine
- 확장성있는 분산 스토리지 제공, 개체와 버켓 단위로 데이터 관리.
- 개체는 데이터 파일과 메타데이터를 가지고 있다. 
- 개체는 분산 환경에 재분배될 수 없고, uri를 가지고 있어서, soap나 rest 기반 인터페이스로 접근이 가능하다.
- 버켓은 다양한 개체를 저장하는 컨테이너다. 

## 분산 스토리지 엔진을 위한 cloud 기반 평가 환경 디자인
- 어떻게 분산 컴퓨팅 환경을 디자인할지.
- Amazon Elastic MapReduce를 다양한 오픈 소스 빅테이터 툴을 지원하는 cloud 기반 플랫폼으로 사용한다.
- S3의 경우 노드 개수를 설정하지 못하여, GeoSpark를 직접 S3에 연결한다. 
- HDFS, MongoDB는 2-6개의 데이터 노드를 사용한다. 
- MongoDB는 slave node마다 config 서버를 둔다. 

## 비교 성능 평가
### 실험 데이터와 쿼리 셋
#### 실험 데이터
다양한 사이즈, 다양한 실세계 데이터 셋이 있다.

- 실세계 데이터 셋: 7343 지점, 5MB. 이로부터 인위적인 데이터를 생성해낸다. 
  - exponential 
  - uniform
  - normal
  - real-world 
- gunther와 여러 연구자들은 uniform, normal, exponential 데이터 분산에 기반한 데이터 생성을 제안했다. 
  - 프레임워크에 기반해, 우리는 실세계 데이터 분산을 추가했다. 
  - 30x30 그리드로 전체 데이터를 나누고, 
  - 각 그리드에 속하는 지점의 비율을 계산해 각 그리드별로 계산된 비율로 지점을 생산한다. 
  - 공분산을 고려하여, python numpy library로 normal and exponential한 분산 데이터를 만들어냈다.
  - 랜덤하게 공간 지점을 생산하여 uniform한 분산 데이터도 만들었다. 
  - 결과적으로, 1000만개의 포인트를 만들어냈다.
- 또한 다양한 사이즈 (백만, 천만, 억, 십억 크기의 사이즈) 데이터 셋도 만들었다. 분산은 고정된 채로.
- 기존 연구들에서 성능을 평가하기 위해서는 오백만에서 20억 사이의 데이터 셋이 필요하다하였고, 1.1기가에서 11기가의 데이터 사이즈가 요구된다고 하였다.
  - 그래서, 10억개/38.5기가 지점이 충분히 많은 범위의 공간 데이터라 할 수 있겠다.

#### 쿼리 셋
실험에서 사용된 네 가지의 쿼리
- circle queries
- bounding box queries
  DE-9IM에 정의된 기본 릴레이션에 포함되어있다. 

- k-NN 쿼리는 쿼리 지점에서 가장 가까운 장소를 찾는 데 유용하다.
- distance join query는 맵리듀스 프레임워크 효과를 레버리징한다.

## 실험 방법
사전 평가로, 1) 몽고디비의 서로 다른 샤딩 전략에 따른 성능 2) 캐싱의 영향을 체크했다.
그러고나서, 1) 분산 데이터 2) 데이터 셋 크기 3) 스토리지 노드 수와 실행기 개수 4) 쿼리 선택에 기반한 데이터 프로세싱 시간을 측정하였다.

실험을 위한 기본 설정은 우선, 데이터 노드 수를 6개로 고정했다. 데이터는 10억개로 설정, 네개의 쿼리를 사용했다.
모든 실험에서 100번의 쿼리를 수행했고 그 평균 프로세싱 타임을 얻었다.

전역 인덱스로 R tree, 지역 인덱스로 Quad tree dldyd. 
GeoSpark SQL로 각 쿼리를 운용했다. 

캐싱 영향을 파악하기 위해, 환경을 구성했다. 이를 하는 이유는 처음 상태 혹은 충분한 메모리가 없을 때의 성능을 관찰하기 위함이다. 
- 콜드 캐시 (메모리에 인덱스와 데이터가 없는 환경) -> Linux command drop cache 선언
- 웖 캐시 (이전에 같은 쿼리를 실행했을 때 메모리에 그 데이터와 인덱스가 있는 환경)

## 실험 결과
### Data sharding
성능에 중요한 영향을 미친다. 왜냐하면 파티션에서 샤드 키를 따라 다양한 샤드 서버가 전체 데이터로부터 나뉘기 때문이다.
그러나, 몽고디비에서 지원하는 내장 공간 인덱스는 shard key로 사용할 수 없기에, 효과적인 샤딩 전략을 만들어야한다. 

Zhang외 몇명은 hilbert curve를 사용했다. 이 논문에서는 랜덤 혹은 space-filling curves 중 하나인 z order에 따른 샤딩을 사용했다.

z-value 계산과 z order를 그 값에 따라 얻는 것은 데이터 샤딩 이전에 한번만 수행된다. 그래서, 쿼리 성능에 영향을 미치지 않는다. 

실제로 실험해본 결과, z order에 따라서 샤딩한 것이 확실히 성능이 좋아졌다. 그래서 몽고디비에서는 이를 이용할 것이다.

### 캐싱 영향
캐싱이 있을 때 훨씬 좋아졌다.

### 데이터 분산이 다를 때의 성능
모든 분산에 있어서 HDFS, S3가 MongoDB에 비해 성능이 나았다. 특히, k-NN 쿼리에서는 몽고디비보다 HDFS가 7.84 ~ 9.89배 나앗다. 

전반적인 쿼리 성능은 s3가 HDFS와 유사하다는 것을 알 수 있다. 그 이유는 EMR에 맞게 HDFS를 확장했기 때문이다.

### 데이터 사이즈가 바뀔 때의 성능
몽고 디비보다 다른 것이 성능이 좋다. 그러나 데이터 사이즈가 커질수록 성능 차이는 줄어든다.
(궁금한 점: 기울기는 훨씬 커졋는데 서로 배수로만 비교를 하는 것이 맞는건가?)

### executor와 스토리지 노드 개수의 성능 영향
executor가 많아질 수록 HDFS, S3가 몽고디비에 비하여 성능 개선이 있다.
이는 HDFS, S3가 더 확장성이 있다는 뜻이다. 

### 쿼리 선택에 따른 성능
쿼리 선택이 증가할수록 쿼리 성능은 전반적으로 낮아진다. 특히, 몽고디비는 더욱 더 낮아진다. 
흥미로운 것은, 다른 것과는 다르게 k-NN 쿼리는 작은 수에 있어서는 지속적인 성능을 보인다는 것이다. 
- 그 이유는 branch-and bound tree 순회가 있어서, 최소 하나의 파티션을 찾고, 그 결과로 모든 공간 RDD는 메모리에 저장되어, 일정한 성능을 보이는 것이다. 

### 분산 스토리지 시스템 성능 분석
1) read 작업 실행 시간 측정
2) mongodb 세가지 실행 시간 비교: 읽기, 스캔, 지역 쿼리(bounding box) -> 스캔이 훨씬 많은 시간이 들고, 지역 쿼리는 80프로 차지한다. 

## 관련 연구
공간 데이터 프로세싱과 그 평가를 위한 데이터와 쿼리 셋을 정의하려는 여러 연구들이 있었다. 
1) 스톤 브레이커 외 몇명은 SEQUOIA를 제안, 공간 데이터 정의를 위한 첫 노력이었다. 
   - 쿼리 셋도 정의했다. 실세계 쿼리: 데이터 로딩, 셀렉션, 조인...
   - 이를 통해서 성능 평가를 수행했다. 
2) Gunther 외 몇 명은 공간 벤치마크를 제안했다. 
   - normal, exponential, uniform 데이터 분산을 고려했고, 공간 조인 쿼리에 집중하고 작은 범위의 데이터 셋을 100만개의 개체로 만들어냈다. 
3) Paton 외 몇명은, PostgresSQL을 Rock & Roll 과 비교할 벤치마크 프레임워크를 제안했다. 
   - 제안된 프레임워크가 다른 공간 데이터 프로세싱 시스템과도 적용될 수 있음을 보여주었다.
4) Ray 외 몇명은, JDBC를 지원하는 모든 데이터베이스를 평가하기위한 벤치마크를 제안했다. 두 가지의 시나리오를 정의했다 : 토폴로지 릴레이션과같은 마이크로 시나리오, flood risk와 같은 매크로 시나리오

GeoSpark의 이전 벤치마크들은 Hadoop과 스파크 기반 프로세싱 시스템 사이 비교에 집중했다. 
1) Lenka 외 몇명은 SpatialHadoop과 GeoSpark 사이의 아키텍처를 비교하였다. 
   - 노드 개수가 변함에 따라 성능을 측정하였다. 
2) Pandey 외 몇명은 Spark 기반 공간 데이터 처리 시스템을 평가하였다. 

이 논문에도 사용된 스토리지 엔진 성능평가를 한 연구들도 있었다. 
1) Agarwal 외 몇명은 몽고디비와 전통적인 관계형 데이터베이스 간의 성능 비교를 하였다. : line intersection, point containmaent에 관련하여. 
2) Makris 외 몇명은 더 나은 스토리지 시스템을 평가하였다. 
3) Dede 외 몇명은 성능, 확장성, 내결함성에 대한 연구를 하였다. 

이 논문의 사전 버전도 있다. 그 때에 비하여
1) cloud 기반 분산 환경 평가
2) 많은 공간 데이터 처리 데이터 확장 셋
3) 확장 비교 실험 
4) 세세하고 확장된 관련연구 

가 달라졌다.

## 결론
GeoSpark를 이용한 공간 데이터 관리 성능을 평가하였다. 세 가지의 분산 스토리지 엔진을 사용했고, 
실 클라우드 컴퓨팅 환경에서 실험을 하기 위하여, EMA 기반으로 실험 환경을 만들었다.
큰 공간 데이터 처리 평가를 위하여, 다양한 종류와 크기의의 데이터 셋을 생성했다.

확장 실험을 통하여, 처리 시간을 평가하였다. 
1) 샤딩 전략 
2) 캐싱 영향
3) 데이터 분산
4) 데이터 사이즈
5) executor 수
6) 쿼리 선택

주요 포인트는 다음과 같다.
1) 전반적으로 몽고 디비가 다른 둘에 비하여 성능이 좋지 않았다. 
2) 몽고 디비 기반 성능은 큰 데이터 스케일에서 개선되었다. 
3) HDFS와 S3 기반 GeoSpark는 몽고 디비에 비하여 더욱 확장성이 있었다.
4) 샤딩 전략은 몽고 디비 성능을 개선했다.
5) s3와 hdfs 기반 GeoSpark는 비슷한 성능을 보였다
6) 캐싱은 전반적인 성능을 올려주었다.
이 결과들은 타겟 분산 환경에서 데이터를 처리할 때, 가장 적절한 스토리지 엔진이 뭔지 결정하는 과정에서 유용하게 사용될 수 있겠다. 

이 논문에서 맵리듀스 처리에 초점을 맞추어 공간 데이터 관리 시스템 성능 평가를 수행했다. 
후의 작업으로, 현 평가를 기반으로 많은 공간 쿼리 타입을 처리할 계획이다. 
특히, 지역쿼리는 다른 데이터 타입들과 결합되었다. 소셜 네트워크-그래프데이터, 언어-지도 기반 서비스

쿼리 타입을 확장하며, 평가 프레임워크에 자연스럽게 더 넓은 시스템 타입을 포함할 수 있다. 


#### 왜 몽고 디비 성능이 개선되었다고 표현하는걸까?
#### 왜 성능평가를 시간으로만 했을까? 



