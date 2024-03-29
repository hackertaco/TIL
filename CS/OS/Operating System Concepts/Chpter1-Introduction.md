# Overview
하드웨어와 유저 사이의 중간다리. 편하고 효율적인 방식으로 유저가 프로그램을 실행하기 위해, 환경을 제공하는 것.
컴퓨터 하드웨어를 관리하는 소프트웨어다. 하드웨어는 정확한 컴퓨터 시스템 작업을 보장하고, 적절한 작업으로 유저 프로그램이 방해받는 것을 막아야하기에, 적절한 매커니즘을 제공해야만 한다.

내부적으로는, OS는 보충을 위해 변한다. 왜냐하면 많은 다른 라인들로 구성되어있기 때문이다. 
새로운 운영체제 시스템을 디자인 하는 것은 주요 업무다. 디자인 시작 전에, 시스템의 목표가 잘 정의되는 것은 중요하다. 
이 목표는 다양한 알고리즘과 전략들 사이에서 선택의 기반을 구성한다.

OS는 크고 복잡하기 때문에, 한땀 한땀 만들어져야한다. 이 하나하나는 조심스럽게 정의된 인풋 아웃풋 함수들과 묘사되어야한다.

OS를 배우기 전에 우선 시스템 스트럭처를 알아야한다. 
시스템 시작, I/O, 스토리지에 대해서 공부한다. 

## 1. 운영체제가 뭘 하는지
컴퓨터 시스템은 하드웨어, 운영체제, 애플리케이션, 사용자로 나누어져있다. 

- 하드웨어: CPU, memory, i/o 기기- 기본적 컴퓨팅 자원을 제공한다.
- 어플리케이션 - 이는 유저의 문제를 해결하기위해 어디에 자원이 있어야할지를 결정한다. 
- 운영체제는 하드웨어와 애플리케이션을 사용하는 것을 조율한다.

컴퓨터 시스템을 하드웨어, 소프트웨어, 데이터로 구성된 걸로 바라볼 수도 있다.
운영체제는 컴퓨터 시스템에서의 작업을 적절한 자원의 사용을 할 수 있게하는 수단을 제공한다. 
정부와 비슷하다고 보면 된다. 그 자체로 유용한 함수는 제공하지않지만, 환경을 제공한다. 

1) 유저 입장
   - 컴퓨터에서 유저의 입장은 그가 사용하는 인터페이스에 달려있다. 
     - PC를 사용하는 자에게는, 사용성을 좋게하는 게 주 목표다. 다양한 유저들보다는 하나의 유저 경험에 집중되어있다.
     - 공유하는 컴퓨터를 사용할 경우에는 운영체게자 자원 효용을 극대화하는 방식을 택한다.
     - 등등 다른 인터페이스에 따라 운영체제가 집중하는 특성이 달라진다.

2) 시스템 입장
   - 컴퓨터가 보기에는, 운영체제는 하드웨어와 밀접히 관련되어있다. 이 맥락에서는, 운영체제를 자원 할당자로 바라볼 수 있다.
   - 컴퓨터 시스템은 많은 자원을 가지고있는데, 이에 대한 매니저로서 운영체제가 역할한다.
   - 조금 다른 시선으로는, 운영체제가 다양한 I/O기기와 유저 프로그램을 통제하는 것이다. 통제 프로그램은 적절하지않은 프로그램의 사용이나 에러를 방지한다.

3) 운영체제의 정의
   - 컴퓨터의 무수한 디자인과 사용례 때문에, 운영체제는 많은 역할과 기능을 담당한다. 
   - 무어의 법칙처럼, 컴퓨터는 사이즈는 작아지고 2배씩 트렌지스터가 발전했다.
   - 운영체제에 대한 완벽한 정의는 내리기 어렵다. 운영체제는 컴퓨터 시스템의 탄생하는 데 생긴 문제점을 해결하기위한 합리적인 방식을 제공한다.
     - 컴퓨터 시스템은 유저 프로그램을 실행하고 문제를 해결한다. 하드웨어는 이 목표로 만들어졌다. 
     - 그런데 이용이 쉽지는 않아서 어플리케이션 프로그램이 만들어졌다.
     - 이 프로그램은 공통으로 사용하는 작업들을 요구했고, 그래서 이 모든 기능들이 하나로 뭉쳐져 운영체제가 탄생했다. 
   - 운영체제으 ㅣ파트가 뭔지를 정의하는 것도 널리 퍼트려진 것이 없다. 
     - 그저 다 잇다고 표현하는것이다.
     - 그러나 시스템에 따라서 다르다. 
     - 커널은 그 중에서도 운영체제에서 항상 돌고있는 것이다.
     - 모바일 기기에서는 커널과 미들웨어도 있다. 

## 컴퓨터 시스템 기관
컴퓨터 시스템의 일반적 구조를 알아야한다. 

1) 컴퓨터 시스템 작업
   - 하나 혹은 이상의 CPU, 공유된 메모리 접근을 제공하는 많은 디바이스 컨트롤러로 이뤄져있다. 
   - CPU와 이 컨트롤러는 병렬로 움직일 수 있다. 메모리 주기를 가지고 경쟁한다. 
   - 공유된 메모리를 순서대로 접근하기위해, 메모리 컨트롤러는 동기화한다. 
   - 컴퓨터가 시작할 때 시작 프로그램이 필요한데, 이를 부트스트랩 프로그램이라고 한다. 
     - 전형적으로 , 이는 Read Only Memory(ROM)에 저장되어있거나 펌웨어라 불리는 EEPROM에 저장돼있다. 
     - 이는 모든 시스템을 시작한다. 레지스터부터 디바이스 컨트롤러까지. 
     - 이 프로그램은 어떻게 운영체게를 로드할지 알아야하고, 시스템을 어떻게 실행할지를 알아야한다.
     - 그래서, 이 프로그램은 운영체제 커널을 위치시키고 메모리에 로드해야한다.
   - 커널이 로드되고 실행되면, 시스템과 사용자를 위해 서비스를 제공하기 시작할 수 잇다. 
     - 커널에 속하지는 않지만 커널이 도는 동안 도는 시스템 작업도있다. 
     - 첫 시스템 프로세스는 init이고, 많은 다른 데몬들을 시작한다. 이 단계가 끝이나면, 시스템은 부팅이된 것이고, 다른 이벤트가 일어나길 기다린다.
   - 이벤트 발생은 하드웨어나 소프트웨어로부터의 인터럽트로 시그널을 받는다. 
     - 하드웨어는 CPU로 시그널을 보내서 인터럽트를 할 것이고,
     - 소프트웨어는 시스템 콜이라는 것으로 인터럽트를 할 것이다. 
   - CPU가 인터럽트되면, 하던 걸 멈추고 즉시 지정된 위치로 실행을 옮긴다. 
     - 지정된 위치는 주로 시작 주소를 포함한다. 이는 인터럽트 서비스 루틴이 위치한 장소다.
     - 인터럽트가 다 실행되면 인터럽티드 된 작업을 재개한다. 
     - 인터럽트는 컴퓨터 아키텍처에서 중요한 부분이다. 각각의 컴퓨터 디자인은 인터럽트 매커니즘이 있지만, 몇몇 기능은 일반적이다. 
     - 인터럽트는 적절한 인터럽트 서비스 루틴에 통제권을 넘겨야한다. 가장 똑바로된 방법은 인터럽트 정보를 조사하기위하여 일반적인 루틴을 촉구하는 것이다. 
     - 이 루틴은, 인터럽트 특정 핸들러를 부를 것이다. 
     - 그러나, 인터럽트는 빠르게 핸들링되어야한다. 미리 지정된 수의 인터럽트만 가능하기에, 필요한 속도를 제공하려면 포인터 테이블이 사용될 수 있다. 
     - 일반적으로, 포인터테이블은 낮은 메모리로 저장된다. 이 위치는 주소를 가지고 있다. 이는 색인화되어서 인터럽트 디바이스에서의 인터럽트 서비스 루틴 주소를 제공한다. 
     - 인터럽트 아키텍처는 인터럽트 지침의 주소를 저장해야한다. 많은 옛 디자인은 인터럽트 주소를 고정되게 가지고있거나 디바이스 넘버로 인덱싱된 주소를 가진다. 
     - 최근은 시스템 스택의 주소를 저장한다. 
2) 스토리지 구조
   - CPU는 메모리에서만 지침을 로드할 수 있어서, 운영할 프로그램은 그곳에 저장되어야한다. 
   - RAM이라는 메인 메모리에 대부분의 프로그램을 돌린다. 
   - 메인 메모리는 DRAM이라불리는 반도체 테크 기술에서 실행된다.
   - 컴퓨터는 다른 메모리도 사용한다. ROM이 그것이다. 이는 변할 수 없다. 
   - 펌웨어도 바뀔 수는 있지만 자주 바뀌면 안되어 거의 정적 프로그램을 포함한다. 
   - 이 모든 메모리는 바이트의 배열로 제공된다. 각각의 바이트는 자체 주소를 가지고 있다. 
     - 이 특정 메모리 주소 로드와 스토어 과정에서 인터랙션이 일어난다. 
     - 로드는 메인 메모리에서 내부 레지스터로 바이트를 옮긴다. 반면 스토어는 레지스터에서 메인으로 옮긴다. 
     - 명확한 로드와 스토어와는 관계없이, CPU는 자동적으로 메인 메모리에서 인스트럭션을 로드한다.
   - 전형적인 실행 주기는 von Neumann architecture와 함께 시스템에서 실행된다. 
     - 지침을 메모리에서 fetch, 인스트럭션을 그 레지스터에 저장. 
     - 디코딩되고 피연산자를 만들어낸다. 메모리 유닛은 그저 메모리 주소 스트림만 본다. 어떻게 생성되었고 무엇을 위한건지는 모른다. 
   - 모든 프로그램이 메모리에 있을 수는 없다. 메인 메모리는 너무 작다. 또한 휘벌성이있다.
     - 그래서, 부차적 스토리지를 제공한다. 
     대표적 부차 스토리지는 Magnetic disk이다. 프로그램과 데이터 모두에 스토리지 제공한다. 대부분의 프로그램은 메모리에 올려질 때까지 디스크에 적재된다.
   - 스토리지 구조는 레지스터, 메인 메모리, 마그네틱 디스크 외에도 캐시, 시디롬, 등등이 있다. 
     - 각 스토리지 시스템은 기본 기능을 제공하고, 나중에 회수될 때까지 datum을 잡는다. 
   - 이 구조는 계층으로 표현될 수 있다. 
     - 위로 갈수록 비싸고 빠르다. 
     - 느리고 비싼건 이용할 필요가 없고, 반도체 메모리가 더 빠르고 더싸기 때문에 안좋은 건 역사로 남았다. 
     - 빠르고 비싼 거 외에도, 이 계층은 휘발성과 비휘발성으로 나뉜다. solid-state disk 위는 휘발적이다. 
     - solid-state disk는 몇몇 변수를 가지고 있지만 다른 아랫것들보다는 빠르다. DRAM에 데이터 저장해두지만, 백업으로 마그네틱 디스크도 두고있다. 
       - 만약 external power가 방해받으면 마그네틱 디스크에 복사한다. 
       - 다시 돌아오면 RAM에 카피한다. 
3) I/O 구조
스토리지는 그저 컴퓨터 내의 많은 IO 기기들 중에 하나이다. 

대부분의 운영체제 코드는 IO 매니징에 있다. 
I/O 작업 시작을 위해, 디바이스 드라이버는 적절한 레지스터를 디바이스 컨트롤러에 로드한다. 
- 이는 이 레지스터를 조사하여 무슨 작업을 해야하는지 결정한다. 이 컨트롤러는 로컬 버퍼에 디바이스 데이터를 불러온다.
- 데이터를 다 불러오게되면, 작업을 끝냈다고 디바이스 드라이버에 보고하고, 드라이버는 운영체제에 컨트롤을 넘긴다. 혹은 상태 정보를 리턴한다.
- 이런 작업은 작은 양의 데이터를 옮기는 데는 좋다.큰 데이터는 너무 높은 오버헤드가 있어서, 이 경우 DMA(direct memory access)가 사용된다. 
- 버퍼, 포인터, 카운터를 세팅하면, 디바이스 컨트롤러가 전체 데이터 블록을 보내거나, 버퍼에서 메모리로 옮긴다. CPU의 개임 없이. 하나의 인터럽트만이 블록별로 생성된다. 바이트 단위 말고. 

## 컴퓨터 시스템 아키텍처
일반적인 구조를 알아봤는데, 컴퓨터 시스템은 일번적 목표의 프로세서 수에 따라 다양한 방법으로 조직될 수 있다. 

1) 싱글 프로세서 시스템 
   - 하나의 메인 CPU, 일반적 지침 수행. 
   - 다른 목적의 프로세서도 가지고 ㅣㅇㅆ는데, 디바이스 특화 프로세서다. 
     - 이들은 제한된 지시 세트를 가지고 잇고, 유저 프로세스는 운영하지않는다. 가끔은 운영체제에 의해 관리되기도 한다. 그들의 다음 태스크와 그들의 상태를 모니터링 한다.
     - 일련의 요청을 CPU로부터 받고, 자체 디스크 큐와 스케줄링 알고리즘을 수행한다. 이는 메인 CPU의 연할을 좀 줄여준다. 이들은 알아서 하기 때문에 운영체제가 이들과 소통할 수 없다. 
2) 멀티 프로세서 시스템
   - 컴퓨팅 지평을 지배한 멀티 프로세서 시스템.
     - 두개 혹은 그 이상의 프로세서를 가지고 있다. 서버에서 처음 등장했고, 데스크톱과 랩톱까지 옮겨갔다. 
     
   - 세 가지 장접. 
     - 증가한 이용량 
       - 더 많은 일을 할 수 있다. 오버헤드느 ㄴ있다. 
       
     - 경제적인 스케일링: 에너지 공급, 스토리지 등을 공유할 수 있다. 더 저렴하다.
     - 신뢰성 증가: 여러개의 프로세서로, 프로세서 하나의 실패가 시스템을 멈추지는 않는다. 느려질 뿐! 
     
    - 여기서 신뢰서 ㅇ증가는 중요하다. 느려지기는 하지만 살아남는 것을 graceful degradation이라 부른다. 
    - 장애 허용 시스템이라 불리는 이건 실패가 발견되고 예측되고 고쳐지기를 허용하는 매커니즘을 요구한다. 
    - 각각의 프로세서는 각 지침을 수행하고 결과를 비교한다. 
    - 결과가 다르다면, CPU는 잘못이고 둘다 정지된다. 그러고 다른 CPU들로 옮겨 또 진행한다. 이는 비싸다.

   - 요즘 사용되는 멀티 프로세서 시스템은 두가지다. 
     - 비대칭 다중 처리 시스템
       - 각각의 프로세서가 특정한 업무를 맡는것.
     - 대칭 다중처리 시스템
       - 가장 많이 사용됨. 운영체제 안에서 모든 잡을 시행한다. 그들은 모두 동료다.
       - 각각은 레지스터와 로컬 캐시를 갖고잇다.
       - 그러나, 메모리를 공유한다. 
       - 신중하게 IO를 통제하여야한다. 
       - CPU가 분리되어있기 때문에, 어떤 건 게으르게 있을 수 잇다. 이러한 비효율은 특정한 데이터 구조를 공유하면 피할 수 있다. 
       - 이 경우 프로세스와 자원을 공유한다. 
     - 이 두 멀티프로세싱 차이점은 하드웨어냐 소프트웨어냐로 결론지어질 것 같다. 
       - 특별한 하드웨어는 비대칭을 사용할수도있다. 
     - 멀티프로세싱은 컴퓨팅 파워 증가를 위해 CPU를 추가한다. 
       - 조합된 메모리 컨트롤러를 가지고 ㅣㅇㅆ다면, CPU를 추가하는 것은 시스템의 메모리를 증가하는 것이다. 
       - 다른 방법은 조합된 게 아니고 분산되게 메모리가 되도록 시스템 변화를 줄 수 있다. 
         - 이 경우, 몇몇 메모리는 더 오래 접근 시간이 걸린다. 
   - 최근 트렌드는 하나의 싱글 칩에 다양한 컴퓨팅 코어를 포함하는 것이다. 그러한 것을 멀티코어라고 한다. 
     - 이는 멀티 칩보다 효율적이다. 게다가 이는 에너ㄹ지를 덜 쓴다. 
   - 모든 멀티 코어 시스템이 멀티 프로세서 시스템이지만, 그 반대는 아니다.
   - 블레이드 서버는 멀티 프로세서와 블레이드 프로세서 보드가 독립적으로 booting되는 점에 있다. 그리고 각각의 운영체제를 가진다. 
3) 클러스터 시스템
또 다른 멀티프로세서 시스템의 종류는 다양한 CPU를 모으는 클러스터 시스템이다. 이는 두개 혹은 그 이상의 코어 시스템 혹은 노드로 이루어져 있다.
- 느슨한 결합
  - 각각은 싱글 프로세서 시스템일수도 있고 멀티코어일수도 있다. 
  - 클러스터라는 개념이 구체적인 것은 아니다. 
  - 가장 일반적으로 받아들여지는 개념은, 클러스터 컴퓨터가 스토리지를 공유하고, LAN으로 연결되어있다는 것이다. 
- 높은 가용성
  - 클러스터 내의 하나 혹은 그 이상의 시스템이 오류가 나더라도 서비스가 지속된다. 
    - 이는 시스템 내에 중복 수준을 높이며 얻을 수 있다. 
    - 클러스터 레이어가 클러스터 노드 위에 돌아가는데, 각각의 노드는 랜을 통해서 서로를 모니터링할 수 있다.
    - 하나가 장애가 발생하면, 모니터링 머신이 스토리지 주도권을 가져가고, 재시작한다. 
    - 유저들은 그저 잠깐의 인터럽션을 경험하게 될 뿐이다.
- 클러스터링은 대칭 혹은 비대칭으로 설계된다. 
  - 비대칭적으로는, 하나는 다른 것을 감시하며 hot-standby mode 상태다. 다른 하나가 장애가 나면, 이는 액티브 상태가 된다.
  - 대칭적으로는 두개 혹은 더 많은 호스트가 서로를 감시하면서도 액티브상태다. 
    - 이는 더 효율적일 수는 있지만, 하나 이상의 어플리케이션이 실행 가능해야한다.
- 네트워크를 통한 여러 컴퓨터 시스템을 포함하기 때문에, 클러스터는 높은 성능의 컴퓨팅 환경을 제공하는 데 사용될 수 있다. 
  - 이는 병렬로 알려진 기술을 포함한다. 그는 프로그램을 여러개의 컴포넌트로 나누는 것이다.
  - 이 경우 일단 각 컴퓨팅 노드가 각 문제를 해결하면, 최종 솔루션으로 결합된다.
- 클러스터의 다른 형태로는 병렬 클러스터가 있다. 그리고 그는 다양한 호스트가 공유된 스토리지에서 같은 데이터에 접근하는 것을 허용한다.
  - 대부분의 OS에는 동시 데이터 접속 지원이 안되어서, 소프트웨어의 특별 버전이 요구된다. 
  - 공유 접근을 제공하려면, 시스템은 접근 제어를 해야하고, 부딪히는 작업이 없게끔 DLM이 필요하다.
- 클러스터 기술은 빠르게 변한다. 몇몇 클러스터 제품은 클러스터 내에서 수십의 시스템을 지원한다. 
  - 그는 Storage area network로 가능하다. 스토리지에 다 연결된다. 
  - 하나의 호스트가 실패해도 같은 데이터베이스를 공유하며 성능과 신뢰성을 증가시킨다. 

## OS 구조
- 멀티 프로그램
  - 항상 CPU가 일을 하게끔 한다.
  - 여러 잡을 메모리에 동시에 유지하고, 메인 메모리는 작기 때문에, 그를 담을 pool을 디스크에 보관해두고, 메모리 할당을 기다리게 한다. 
  - 사용자 인터랙션을 제공하지는 않는다.
    - 이를 위해서는 Time sharing이라는 멀티 프로그래밍의 논리적 확장이 필요하다.
      - 이 환경에서는, CPU가 다양한 job을 스위칭하며 사용자의 인터랙션이 가능하게 한다. 
      - 이는 입출력 기기로 실행되고, 반응 시간이 몹시 빨라야한다. 
      - 시스템이 몹시 빠르기 때문에 유저는 시스템이 자신만을 위해 작업되는 줄 착각한다.
- time-shared
  - CPU 스케줄링과 멀티프로그램을 이용한다. 
  - 메모리에 로드되는 프로그램을 프로세스라고 하고, 그것이 실행되면, 끝나거나 I/O를 수행하기 전 짧은 시간동안 실행된다. 
- 메모리 동시 보관 필요
  - 여러 잡들을 메모리에 가져와야하는데, 공간이 없다면, 시스템은 그 중 선택을 해야만한다. 이를 잡 스케줄링이라 한다. 
  - 그리고 여러 잡들이 동시에 실행될 준비가 되었다면, 시스템은 어떤 것을 먼저 실행할지 선택해야하고, 그를 CPU 스케줄링이라 한다. 
- swapping
  - Time sharing을 할 때, OS는 합당한 반응 시간을 보장해야한다. 이는 스와핑으로 해결되고, 메인 메모리에서 디스크로 프로세스가 스왑되는 것이다. 
  - 더 일반적인 방법은 가상의 메모리를 사용하는 것이다. 
    - 이는 실제 메모리보다 더 큰 프로그램을 돌릴 수 있게 해준다. 
    - 더불어 메인 메모리를 크고 통일된 스토리지 배열로 추상화시켜, 논리적인 메모리로 보이게 한다. 
- file system
  - 디스크 컬렉션에 위치한다. 
