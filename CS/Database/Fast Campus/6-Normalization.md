## 정규화의 개념
- 관계형 데이터베이스를 설계할 때, 중복을 최소화하도록 데이터를 구조화하는 프로세스
- 함수적 종속성을 이용하여 연관성 있는 속성들을 분류
- 각 릴레이션들에서 이상 현상이 생기지 않도록 하는 과정

-> 여러 테이블로 쪼개 나가는 과정.

* 불필요한 데이터 제거, 데이터 중복 최소화
* 데이터베이스 구조 확장 시 재 디자인 최소화 
* 무결성 제약조건 시행 간단히
* 이상 현상을 방지하기 위해! 
  * 삽입 이상: 데이터를 저장할 때 원하지 않는 정보가 함게 삽입되는 경우
  * 갱신 이상: 중복된 튜플 중 일부만 갱신해서 정보의 모순성이 발생
  * 삭제 이상: 유지돼야할 정보까지도 연쇄적으로 삭제되는 경우

이런 이상 현상은, 관련없는 속성을 다 모아서 하나의 릴레이션으로 만들었기 때문이다.
그래서 작은 여러개의 릴레이션으로 분해해야한다.
함수적 종속성으로 관련성 판단!

### 함수적 종속성
- 릴레이션의 속성들 사이의 관계 표현.
- 주로 기본키와 다른 키 속성들 사이의 관계를 표현.
- 이를 통해 정규화를 실행한다.
X -> Y

### 추론 규칙
- Reflexive Rule: 만약 Y가 x에 포함되면 X -> Y
- Augmentation Rule: X->Y이면 XZ -> YZ
- Transivtive Rule: X->Y이고 Y->Z 이면 X->Z
- Union Rule: X->Y, X->Z이면 X-> {Y,Z}
- Decomposition Rule: X->{Y,Z}이면 X-> Y이고 X->Z이다
- Pseudo transitive Rule: X->Y YZ-> W이면 XZ -> W

이 규칙을 가지고 정규화를 이루어낸다.

## 정규형의 종류 
#### UNF(Unnormalized Form): 
기본키를 가지고 튜플을 식별해야한다. 
#### 1NF: First Normal Form: 
UNF에서 원자값을 갖지 않는 경우 다른 릴레이션으로 분리해서 두개로 쪼갠다.
릴레이션의 기본키가 분리된 릴레이션의 외래키로 설정됨

#### 2NF: Second Normal Form
기본키에 속하지않는 속성의 경우 기본키에 함수적 종속이 되어야한다.
하지만 이 경우, 데이터 중복이 발생.

- 1NF를 만족하고, 기본키가 아닌 속성들은 기본키 전체에 함수적 종속이 되어야한다.
  - 기본키가 두개일 경우, 1에 종속적 컬럼만 가진 릴레이션/2에 종속적 릴레이션 서로 분리

#### 3NF: Third Normal Form
- 2NF를 만족하면서, 이행적 종속이 없어야한다. (Transivtive Rule)
- Z역할을 하는 속성을 분리하여 릴레이션으로 만들게된다.
- 이걸 만족하면 정규화 되었다고 한다.

#### BCNF: Boyce-Codd Normal Form
- 모든 함수 종속관계에서 X로 가능한 집합의 속성이 모두 슈퍼키이면 BCNF를 만족한다.


- OLAP 애플리케이션인 경우, 성능 향상을 위해 낮은 수준의 정규화를 추구하기도 한다. 
  - 많은 조인이 발생하면 코스트가 있으므로, 성능을 위해 Denormalization으로 테이블을 묶거나 데이터의 복제 사본을 추가하기도 한다.

#### 4NF: Fourth normal form
- Multi-valued dependency
  - 튜플이 생성될 때 속성들 사이의 관계
  - 멀티밸류를 가질 수 있는 것에 대한 식을 정리한 것
  
- BCNF를 만족하면서, 릴레이션의 모든 X->->Y의 경우 X가 슈퍼키인 경우

#### 5NF: Fifth Normal Form
- 릴레이션T의 부분 속성 집합{A.b.c}를 조인한 결과가 릴레이션 T와 같을 때!를 조인 디펜던시라고 한다.
- 여러개의 릴레이션으로 분해했을 때, 나눠진 릴레이션이 기존 릴레이션의 슈퍼키를 가지며 더이상 무손실 분해가 불가능할 때!
- 즉 나누었다가 다시 합쳤을 때 나눈 대상과 조인을 한 대상이 같지 않으면, 나눈 대상이 5NF

#### 6NF
- 대표키하나에 하나의 키를 가지게끔 해야하기 때문에, 테이블이 몹시 많다. 
- aggregation에 좋다. (OLAP에 좋다.저장공간이 절약된다)


## 정리
1. 요구사항
2. ER 다이어그램
3. 논리적 설계. 스키마 만들고
4. 정규화를 통해 릴레이션 분해

번외: ad hoc 디자인을 통하여 생성 => 정규화를 통해 테스트, 좋은 디자인으로 변화하기도

### ER 다이어그램과 정규화
ER 통해 (릴레이션 만들고), 정규화를 안할 수 있게 하면 좋지만,
함수적 종속성이 생길 수 있고, 정규화를 통해 분해 과정을 거친다.!

### Denormalization
무조건 정규화가 좋은 것은 아니지. 조인을 하게되면 오버헤드가 생기기 때문이다.
- 업데이트가 거의 발생하지 않고, 조회 성능이 중요할 때
- 빠른 조회 성능 제공
- 중복 데이터 저장으로 인해 저장 공간이 더 필요하게 되고 업데이트가 느려진다. 
- 추가적 코딩 필요할수도..

### Materialized View
- 조인 쿼리에 대한 Materialized view 생성
- 테이블 형태로 저장되어 비정규화와 똑같은 성능 제공
- 추가적인 저장 공간이 필요하고 view 업데이트 비용이 발생한다.
- 그러나, 이상현상에 대한 에러처리는 필요가 없다.

### 정규화 과정을 통해 발견 못하는 디자인 이슈들?
- 새로운 데이터 추가될 때마다 컬럼 추가가 필요한 경우..
- 새로운 데이터가 추가될 때마다 테이블 추가가 필요한 경우..

