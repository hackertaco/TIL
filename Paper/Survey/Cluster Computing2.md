## An overview of the Hadoop/MapReduce/HBase framework and its current applications in bioinformatics

next-generation sequencing과 같은 컴퓨팅 문제로, HPC는 중요해졌다. 
HPC:: SAN에서 호스팅되는 시스템 클러스터 전체에 배포하는 것.

### hadoop
- 하드웨어 변경이 거의 필요하지 않다.
- 큰 스케일의 분산데이터 분석을 하는 데 사용한다.

1. 컴포넌트: 맵리듀스 패러다임을 사용해 클러스터 노드 사이를 이동하여 병렬 프로세싱을 진행한다. Hadoop Distributed File System이라는 강하고, 장애를 견딜 수 있는 시스템을 제공한다.
2. 데이터 지역성: 데이터를 자동으로 분배한다. 즉, 작업하는 데이터에 따라서 맵 태스크를 스케줄링한다. 
3. 장애를 견딜 수 있고, 무공유 아키텍처: task들끼리는 의존하지 않는다. 리듀서 사용을 위해 매퍼를 사용하는 게 아니라면. 또한 노드는 자동으로 실패를 핸들링한다. 
4. 신뢰: 데이터는 여러개의 노드로 복제된다.
5. 프로그래밍 지원: MPI와 같은 병렬 프로그래밍과는 다르게, 데이터 흐름은 불명확하고 자동으로 다뤄진다. 
6. 맵리듀스 패러다임: 장애를 견딜 수 있는 분산 컴퓨팅시스템을 실행하기 위해, Map/Reduce를 도입한다. 
   - 여러 단계가 있는데, 각각은 병렬로 행해지고, key-value로 이뤄진다. 
   - Input → Map() → Copy()/Sort() → Reduce() →Output
   - Map 단계에서 key-value로 데이터를 매핑한다. 리듀서에서 집계된다. 리듀스 단계에서는 다른 key-value 세트가 만들어진다. 
7. HDFS: 기존 관계형 DBMS보다 지속적인 업데이트를 덜 잘 지원한다. 또한, 직접적으로 OS에 마운트 될 수 없어, HDFS를 통한 데이터가 이상할 수 있다. 

하둡 말고도 다른 오픈소스 프로젝트가 하둡을 기반으로 만들어졌다.

### Hive
- 데이터 warehouse. 임시 쿼리하고 더 복잡한 분석을 하는 데 사용한다. 
- 배치 프로세싱 용. 온라인 트랜잭션 용은 아니다. 실시간 쿼리를 제공하지않는다.

### Pig
- 컴파일러가 맵/리듀스 sequence를 만들어내는 프레임워크.
- 배치 프로세싱 용. 

### Mahout과 하둡의 확장
- 그저 큰 스케일의 데이터 프로세싱은 아니다. 
- 여러 언어와의 통합도 가능하다.

### Cascading
- 장애 극복 가능한 데이터 처리 workflow를 정의하고, 실행하기위한 api를 제공

### HBASE
- 하둡 기반의 중요한 프로젝트. 랜덤으로 실시간 읽기/쓰기 접근을 하며 분산되고, 장애 극복가능한 스케일러블한 데이터베이스를 추가한다.
- 각각의 Hbase 테이블은 다면성의 흩어진 맵에 쌓인다. 
- 모든 테이블 액세스는 기본키를 통한다. sql 언어가 기반에 없지만, 결합 가능하다. 
- 테이블은 여러개의 영역으로 구성되어있다. startKey, EndKey로 정의된다. 