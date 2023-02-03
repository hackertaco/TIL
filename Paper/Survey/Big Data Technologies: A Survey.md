#### https://www.sciencedirect.com/science/article/pii/S1319157817300034
- 2017년 논문
- 2023/02/03

### 이 논문의 목적
- 기존 관련 논문들은 알고리즘이나 아니면 빅데이터 자체의 필요성에만 집중을 했다. 
- 빅 데이터의 흐름에 대응하기 위해 나온 다양한 기술들을 조사, 목적에 맞게 해당 기술을 잘 조합해 사용하도록 돕고자 한다.

### 논문 흐름 전개 방식
- Data Storage, Data Processing, Data Querying, Data Access, Data Management Layer로 층위를 나누어 각 기술 사용, 특징, 한계 등을 정리한다.

## Hadoop 생태계로 이뤄내는 빅데이터
Hadoop은 대표적인 빅데이터 기술.
- 병렬과 분산 파일시스템 덕분에 빠르게 장대한 데이터 셋을 처리할 수 있고, 모든 데이터를 메모리에 복사하지 않기 때문에 네트워크나 서버에 부하를 주지않으며, 서버에 데이터를 복제해 falut-tolerance를 보장한다. 

### 1. data storage layer: HDFS, HBase
Hadoop이 데이터를 store하기위해, 파일 시스템으로는 HDFS를, non relational database로는 HBase를 사용한다.
- HDFS는 일반적인 파일시스템 목적으로 만들어지지 않아, 긴 대기시간 작업을 하는 batch 프로세싱 스토리지다. 대신, 비용 절감, 결함 허용, 이식성, 네트워크 밀집을 줄여주는 등의 장점이 있다. 
- HBase는 낮은 대기시간 작업을 위해 만들어졌다. column-oriented key/value data model에 기반한다. 기존 관계형 데이터베이스보다 유연하다. 그러나 SQL 지원을 하지 않는다. 

### 2. data processing layer
MapReduce와 YARN은 하둡 데이터를 실행하는 두 가지 옵션이다. 
YARN이 보다 일반적이다.

- MapReduce는 효율적인 매커니즘으로 데이터 프로세싱을 간소화한다. Map과 Reduce 하위 기능을 이용한다. 
- YARN은 더 일반적이고, 더 나은 확장성과 병렬성, 자원 관리를 제공한다. 배치, 실시간 프로세싱 모두를 지원하고, MapReduce API와 양립 가능하다. 
- Cascading은 발전된 쿼리와 복잡한 workflow를 다룬다. 

### 3. data querying layer: Pig, JAQL and Hive
- Pig는, 병렬 실행을 지원해서 MapReduce의 복잡도를 줄인다. Hive보다 더 많은 데이터 타입을 지원한다. 스키마를 요하지않는다. 로컬에서와 하둡 분산 환경 모두를 지원한다. 
- JAQL은 Hadoop 기반 선언형 언어다. high level query를 맵리듀스로 변환한다. JSON 포맷을 쿼리하기 위하여 만들어졌지만, 다른 타입들도 쿼리가 가능하다. 따라서 스키마가 따로 없다. 
- Hive는 Hadoop의 사용을 간단하게 하기위해 설계된 데이터 웨어하우스 시스템이다. HDFS를 통한 데이터를 관리하고, 테이블 모델에 기반한다. SQL-like 언어도 제공한다. 실시간 트랜잭션에는 맞지않다. Hive 또한 큰 스케일의 작업을 위해 설계되어서 작은 작업이어도 시간이 걸린다. schema-on-read, multiple schema를 지원한다. 

### 4. data access layer
#### ingestion- Sqoop, Flume, Chukwa
#### streaming- storm, spark
#### storage management- HCatalog

### 5. data analytics layer
- Mahout
- R: 제한된 용량, 빠르지는 않다. 

### 6. data management layer
#### Coordination and Workflow

## Hadoop Distributions
하둡 인프라를 발전시켰음에도 불구하고, 다양한 자원들에 다양한 버전의 모듈이 뒤섞여서 양립하지 못할 수도 있다. 
그래서 몇몇의 vendor들은 각각의 모듈을 만들어 분산환경에 패키징했다. 
이를 통하여 양립성, 보안, 성능 등을 보장한다. 

- Cloudera
- HDP
- EMR
- MapR
- ...