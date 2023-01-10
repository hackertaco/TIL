지난 몇년간 컴퓨터 프로세싱 파워, 스토리지 등에 비약적 발전이 있었다. 
그러나, 아직은 슈퍼 컴퓨터로 풀지 못하는 복잡한 문제들이 많다. 
이는 방대한, 이질적인 자원들로 이뤄낼 수 있다.
컴퓨팅 영역에서, 인터넷의 많은 인기와 사용, 혹은 네트워크의 높은 속도로 인해 많은 변화가 탐지되었다. 

그 기술들인 분산 컴퓨팅, cluster 컴퓨팅, 유틸리티, 그리드, 클라우드 컴퓨팅 review를 하고자 한다.

## Introduction
컴퓨팅은 컴퓨터와 그 시스템이 운영되고 구조화되는 방식을 묘사한다. 이론, 시스템, 어플리케이션의 주요 측면은 ㅣ술, 엔지니어링, 디자인, 수학, 등의 원칙에서 나온다.

처음에는 병렬 컴퓨팅 -> 분산 -> 그리드 컴퓨팅 -> 클라우드 컴퓨팅으로 계속 발전해 나갔다.

## Distributed Computing
두개 혹은 이상의 컴퓨터가 네트워크로 소통하며, 프로그램의 서로 다른 부분들이 동시에 일어나는 것.
그는 또한 서로 다른 부분들이 같은 컴퓨터 내에서 두개 혹은 이상의 프로세서로 동시에 도는 것을 말하기도 한다.

둘 모두 다, 동시에 돌아가기 위하여 프로그램이 나눠져있어야한다.
개체가 서로 통신하기 위하여, 기준들이 있어야한다. 
CORBA, DCOM이 그것이다.

## Utility Computing
유연함, 경제적인 측면 때문에, 유틸리티 컴퓨팅은 몹시 인기있다. 후에 나올 컴퓨팅은 이 유틸리티 컴퓨팅에 기반을 둔다.

온디맨드, 사용한만큼 컴퓨팅 서비스를 제공하는 과정이다. 
스토리지, 컴퓨팅 파워가 하나의 타임 셰어링 컴퓨터보다 훨씬 크다. 그 이유는 가상화를 그려내기 때문이다.
이러한 목적에서, 다양한 서버는 백엔드에서 사용된다. 이는 제공자가 관리한다.

## Cluster Computing
- 병렬 혹은 분산 프로세싱 시스템의 한 종류, 상호 연결된 하나씩의 컴퓨터가 하나인 것처럼 함께 일한다.
  - 항상 그렇지는 않지만, LAN에 연결되어있다.
- 노드는 하나 혹은 여러개의 프로세서다.
- 비용 절감 가능!
- 하나의 컴퓨터보다, 성능과 접근성이 향상된다. 
- 주요한 컴포넌트들
  - Multiple High Performance Computers (PCs, Workstations,
    or SMPs)
  - State-of-the-art Operating Systems (Layered or Micro-kernel
    based)
  - High Performance Networks/Switches (such as Gigabit
    Ethernet and Myrinet)
  - Network Interface Cards (NICs)
  - Fast Communication Protocols and Services (such as Active
    and Fast Messages)
  - Cluster Middleware (Single System Image (SSI) and System
    Availability Infrastructure)
## Grid Computing
- 다양한 도메인에서의 컴퓨터 자원을 결합하는 분산 아키텍처
- 슈퍼 컴퓨터처럼, 컴퓨터들은 인터넷에 의하여 느슨히 연결되어있고 태스크를 독립적으로 처리한다. 
- 전형적으로, 그리드는 다양한 태스크를 수행하면서도, 추가적으로 특별한 업무를 수행할 수 있다.
- 두 가지의 작업으로 나뉜다.
  - data grid: user sharing 통제와 데이터 관리에 사용되는 큰 분산 데이터 셋을 다룬다. 가상 환경을 만든다. 
  - CPU scavenging grid: 한 pc에서 다른 pc로 프로젝트를 옮기는 것. 
## Cloud Computing
- 로컬 디스크가 아닌, 인터넷 위에 정보를 접근하고 쌓는 것.
- 인터넷 베이스 컴퓨팅
- 그리드와 비슷
