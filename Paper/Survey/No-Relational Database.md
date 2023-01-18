## Survey on NoSQL Database 

NoSQL 배경, 데이터 모델, 기본 특징 등을 묘사

### Introduction
인터넷과 클라우드 컴퓨팅의 발달로, 다양한 종류의 어플리케이션이 등장했고, 데이터베이스 기술이 더 필요하게 되었다.
- read, write의 높은 동시성(낮은 지연과 함께)
- 효율적인 빅데이터 스토리지와 접근 요구
- 높은 확장성과 가용성
- 낮은 관리운영비용
- 기존 RDB의 느린 read write
- 기존 RDB의 제한된 용량
- 기존 RDB의 확장 어려움

이러한 요구를 충족하기위해, 다양한 데이터베이스 종류가 생겨났다.
일반적으로, 이러한 데이터베이스는 전통적인 RDB와는 다르다.

### Features, data model and classification
#### NoSQL 기능
1) read write의 빠른 속도
2) 거대한 스토리지 지원
3) 확장이 쉬움
4) 비용이 낮음
반면에, 적절하지 않은 부분도 잇는데, SQL을 지원하지 않고, 트랜잭션의 부족이나 (2011년 기준) 미성숙함 등이 그러하다

#### Data Model
1) Key-value
value가 Key에 대응한다. 구조는 더 간단하지만, 쿼리 속도는 더 높다. 
기본키로 쿼리하거나 작업을 수정하는 것 또한 잘 지원된다.
2) Column-oriented
Table을 데이터 모델로 사용하지만, 테이블 연관은 지원하지않는다. 
데이터는 컬럼으로 저장되고, 각 컬럼은 database의 index다. 쿼리와 연관된 컬럼에 접근하는 것은 I/O 를 줄인다. 각각의 컬럼은 하나의 프로세스로 다루어진다. 
전체적으로 데이터 웨어하우스와 집계 어플리케이션에 적절하다. 
3) Document
Key-value와 흡사하다. 그러나 document는 시맨틱하고, JSON이나 XML 포맷으로 저장된다. 부차적인 인덱스를 만들어낼 수 있다.

#### CAP theorem and NoSQL database classification
2000년 Eric Brewer가 제창한 CAP theorem.
일관성, 가용성, 파티션 허용 세개를 의미한다. 
메인 아이디어는 분산 시스템이 세가지 모두를 충족시킬 수는 없지만, 두개는 충족이 가능하다는 것이다. 

NoSQL 예비 분류는 다음과 같다.
- Concerned about consistency and availability
  - 전통적 관계데이터베이스
- Concerned about consistency and partition tolerance(CP) 
  - 분산 노드에 데이터를 저장하지만, 또한 일관성을 유지한다. 그러나 가용성은 좋지못하다.
  - BigTable, HBase, MongoDB, Redis, MongoDB...
- Concerned about availability and partition tolerance (AP) 
  - 가용성과 파티션이 보장된다.
  - Voldemort, Tokyo Cabinet...

## Mainstream NoSQL database
### Key-value database
#### 1. Redis
- 데이터가 메모리에 전체가 로드되어서, 모든 작업은 메모리에서 진행되고, 주기적으로 하드 디스크에 비동기적으로 저장한다.
- 순수한 메모리 작업은 성능이 참 좋은데, 초당 10만개의 read, write 작업을 할 수 있다.
- Redis는 List, Set을 지원하고 다양한 관련 작업을 지원한다.
- 최대 값은 1기가 바이트로 제한된다.
- 주 단점은 물리적 메모리에 데이터베이스 용량이 한정된다는 것이다. 따라서 빅데이터 스토리지로 사용되기가 어렵고 확장성이 좋지않다. 
- 작은 단위의 데이터를 다루는 데 매우 좋은 성능을 보인다.

#### 2. Tokyo Cabinet- Tokyo Tyrant
- TC는 높은 성능 스토리지 엔진이다. TT는 높은 동시성 서버로 멀티스레드를 제공하면서, 이는 초당 4-5백만번을 읽고 쓴다. 
- read, writedp 좋은 성능을 보이지만, TC는 믿을만한 데이터 지속 매커니즘을 사용한다. 
- TC는 key-value 뿐 아니라, 간단한 작업들도 한다. 
- 주 단점은 데이터가 십억 레벨로 올라가게되면 동시 write 성능은 현저히 떨어진다는 것이다.

#### Flare
data server 뒤에 노드 서버를 추가해서 사용자가 동적으로 데이터 서버를 추가하거나 없앨 수 있고, 실패를 방지한다. 
그러나, memcached 프로토콜만 사용하여서, TC 테이블 데이터 구조는 사용할 수 없고, Key-value 데이터 구조만 사용할 수 잇다. 
확장성은 좋다. 

### Column-oriented database
행으로 저장되던 것을 파괴하지는 않았지만, 아키텍처적으로 압축, 무공유, 병렬 프로세싱, 컬럼 기반 데이터베이스는 데이터 분석에 높은 성능을 유지할 수 있게 한다. 

#### Cassandra
- 매우 유연한 스키마. 처음에 스키마 디자인을 요구하지 않고, 필드를 추가하고 삭제하는 것이 몹시 편하다.
- range query를 지원한다. Key로 레인지 쿼리를 할 수 있다.
- 높은 확장성: 실패하는 지점은 전체에 영향을 줄 수 없다. 선형 확장을 지원한다. 
많은 데이터베이스 노드로 구성되어있고, read 작업은 특정 노드에 라우팅 될 것이다.
- 클러스터와 관련해, 노드를 추가하는 것 만으로 확장할 수 있다. 
- 많은 데이터 구조와 강한 쿼리 언어를 제공한다.

#### Hypertable
1000개의 노드로, HDFS, KFS에 적용 가능하다.
write 속도와 read 속도가 빠르다. 그러나, hypertable을 사용하는 어플리케이션이 많지않다. 

### Document database
높은 read, write 동시적 성능을 보이지않지만, 빅데이터를 저장하게 하고 좋은 쿼리 성능을 보장한다. 

#### MongoDB
관계형 데이터베이스와 비관계형 데이터베이스 사이에 있다
- 복잡한 데이터 타입을 지웒나다 
- 파워풀한 쿼리언어를 제공한다: 인덱스를 지원, 싱글테이블에서 대부분의 쿼리같은 함수를 허용한다.
- 빅데이터 접근에서 속도가 빠르다. 

#### CouchDB
- 유연, 장애 허용, 
- 데이터 일관성을 위하여 ACID를 따른다. 
- 그러나 동시 read, write가 별로다

## 결론
- Data model
- CAP Support
- Multi Data Center Support
- Capacity
- performance
- query API
- Reliability
- Data Persistence
- Rebalancing
- Business Support
들을 NoSQL 선택시 고려해야한다.
- 
