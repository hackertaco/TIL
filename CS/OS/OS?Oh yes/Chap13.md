## 다중처리
한 계산의 서로 다른 부분들을, 실질적으로 동시에 수행하기 위해 다수의 처리기를 사용하는 것
좁게는 병렬, 넓게는 분산 처리를 포함한다. 

## 약결합과 밀결합
### 약결합
- 두 개 이상의 독립된 시스템을 통신선으로 연결한다. 
- 각자가 운영체제와 메모리를 가지고 있으며, 필요할 때 메세지 전달이나, 원격 프로시저 호출로 통신을 한다. 
- 통신선으로 서로 다른 시스템의 파일을 참조할 수도 있고, 작업을 보낼 수도 있다.
- 처리기의 위치와 접근코자 하는 데이터가 있는 메모리 위치에 따라 접근 시간 편차가 매우 크다. 통신선을 통해 서로 접근해야 하기 때문이다.
- 이를 보통 분산 처리라고 하는 경우가 많다

### 밀결합
- 여러 처리기 간에 하나의 메모리를 공유한다.
- 그 공유하는 메모리에 있는 운영체제가 모든 처리기들과 시스템 하드웨어를 제어한다.
- 처리기 간의 통신도 공유 메모리에 의해 이뤄진다.
- 공유메모리에 대한 접근 경쟁이 빈번하고, 이를 해결하기 위해 결합 스위치라는 하드웨어 기법을 사용한다.
- 모든 처리기가 공유 메모리에 대한 접근밖에 없어서 편차 없이 매우 빠르다.
- 이를 주로 병렬처리 시스템이라고 분류한다.

## 병렬처리 시스템
병렬구성의 정도에 따라 데이터 스트림, 명령어 스트림을 기준으로 병렬성이 증대되는 순서에 따라 구분한 Flynn의 분류가 있다. 
- SISD(하나의 명령어 하나의 데이터): 폰 노이만 구조. 병렬처리가 없는 단일 처리기 시스템
- SIMD(하나의 명령어 여러 데이터): 배열 프로세서. 여러 개의 처리기에 동일한 명령을 전달. 서로 다른 데이터에 대하여 동일한 연산을 수행한다. 
- MISD(여러 명령어 여러 데이터): 현실적으로 불가
- MIMD(여러 명령어 하나의 데이터): 각 처리기들이 서로 다른 데이터에 대해 서로 다른 연산을 수행. 제대로 된 병렬처리 시스템

### 여러 구조
- 다중 처리기
  - MIMD에 속하며, 대부분의 경우 밀결합 시스템이다. 
  - 결함 허용이 대표적 장점 중 하나다. 복구 기능도 있어야 한다.
  - 캐시 일관성 문제는 해결되어야 한다. 캐시와 메모리 간의 불일치성을 어떻게 해결할 것인지 고민해야한다.
- 파이프라인 구조
  - 다수의 명령들이 동시에 서로 다른 실행 단계에 있게해 성능을 향상 시킨다.
- 배열 프로세서 구조
  - SIMD. 독립적인 태스크들을 각기 다른 명령으로 병렬 수행해야 하는 환경에는 적합하지 않다. 
- Systolic 배열 구조
  - 배열 프로세서 구조와 유사하지만, 처리기들 중 맨 처음과 마지막만 메모리에 접근할 수 있게 하여 메모리에 대한 접근 경쟁을 해소하는 구조
- Superscalar 구조
  - 파이프라인 구조를 여러 개 사용, 한 싸이클에 하나 이상의 명령들이 동시에 실행

### 데이터 플로우 컴퓨터
폰 노이만 구조의 시스템들이 제어흐름에 기반하는 순차 처리기인데 반해, 명령의 실행에 필요한 데이터들이 이용 가능해지는 시점에서 실행되는 방식을 데이터 플로우 컴퓨터라 한다. 
여러 연산을 병렬로 수행할 수 있다.

성능이 순차 처리에 비해 훨씬 좋다.

### 병렬성의 탐지
프로그램에서 동시에 실행될 수 있는 부분들을 찾아내고, 이들이 실제로 동시에 실행되게끔 해줘야한다.
#### 병렬성의 명시
- 프로그래머가 명시하는 것.
- 프로그래밍 언어는 병렬성을 표현할 수 있는 구조여야하고, 컴파일러도 있어야 한다. 
- 그러나 시간이 더 소요되고 실수가 쉽다. 

종류는
- Parbegin/parend
- and 구조
- fork/join/quit 구조
  - parbegin/parend/and 구조로는 표현할 수 없는 병렬처리를 가능하게 한다. 

#### 병렬성의 자동 탐지
- 순환 분배
  - 순환문 For 내의 문장들이 상호 종속성이 없어 병렬로 실행이 가능한 경우, 컴파일러는 이를 찾아 병렬 실행 구조로 바꾸어준다.
- 트리 높이 감축
  - 연산자 선행 규칙들을 이용하여, 병렬 실행이 가능한 기계어 코드를 만든다. 

### Never wait
쉬고 있는 처리기를 사용될 가능성이 보이는 작업을 순서와 관계 없이 실행하게 하여 실행 속도를 높이자는 생각이다. 
if문이 있을 때 그 아래의 코드도 실행해서 if가 수행되게 되더라도 유휴 처리기를 이용했어서 손해가 없다

### Fetch-and-add
- 사용가능한 처리기의 수에 민감하지 않다. 
- 처리기들의 상대적인 속도 차에도 영향 받지 않는다. 
- 구현비용이 비싸다
- 공유 변수에 대한 접근경쟁 해소. 접근 요구를 순서화한다.

### 병렬 운영체제의 종류
독립적으로 병렬 실행되기 위해, 커널 구조를 구성하고 사용 가능한 처리기들을 할당해 주는 일들이 필요하다. 
프로세스 할당, 부하균형, 시스템 재구성 기능 등이 필요하다.
#### 병렬 처리 위한 운영체제의 구조
- Master/Slave
  - master는 입출력과 계산
  - slave는 계산위주
  - 그런데 이 경우 하나의 고장은 다른 시스템의 고장으로 이루어진다는 문제가 있다. 
- 독립 운영체제
  - 구조적으로는 약결합과 다를바 없다. 그 이유는 인터럽트도 각 처리기에서 해결하고 각자의 운영체제를 가지기 때문이다. 
  - 서로 상호배제를 지키도록 신중히 설계
  - 신뢰성이 높다
  - 그러나, 일이 밀리는 처리기가 있을 수 있다.
- 대칭적 구조
  - master/slave의 단점 보완. 모든 처리기들이 동등히 운영체제를 실행할 수 있는 권한을 가진다. 

## 분산처리 시스템
통신 네트워크를 통해 서로 약결합된,
메모리와 클록을 공유하지않는 처리기들의 집합이다. 

자신이 가지고 있는 자우ㅡㅓㄴ: 지역. 그 외 자원: 원격

- 장점: 
  - 자원의 공유로서 연결된 모든 사이트가 보유하는 자원을 사용
  - 특정 연산이 동시에 실행 가능한 부분연산이면 연산 분산시켜 연산 속도 향상
  - 소형 시스템들을 추가로 연결하며 성능의 개선이 가능
  - 가격대비 성능 우수
  - 신뢰성과 가용성 역시 우수

그러나, 교착상태 문제, 프로세스 동기화 제공 등의 문제가 있다.

### 분산 운영체제의 운영
대표적 기능: 투명성
분산 운영체제는 분산 시스템 전체를 가상의 단일 호스트 환경으로 보이게 해야한다. 

지역 운영체제를 확장한 형태 = 분산 운영체제

커널의 크기에 따라 모놀리식과 마이크로로 나뉨
- 모놀리식: 단일 시스템용 운영체제의 서비스 기능 각 호스트에 탑재
  - 호스트 간 중복배치 
  - 메모리 낭비
- 마이크로: 최소한의 기능
  - 운영체제 크기 최소화
  - 서비스 프로세스가 많아서 오버헤드 발생
  - 모듈화, 개방성

#### 네트워크 운영체제
사용자는 원격 자원을 이용하기위해 원격 호스트에 명시적으로 로그인, 혹은 원격 호스트에서 자신의 호스트로 자료를 명시적으로 전송시켜야한다.
1. 원격 로그인: 텔넷
2. 원격 파일 전송: FTP
문제는 사용자가 다른 환경에 알아서 적응해야한다는 것이고, 보다 편리하게 접근하기위한 분산운영체제가 잇다.

#### 분산 운영체제
지역 자원에 접근하는 방법과 동일하게 원격 자원에 접근 가능하다. 

- 데이터 이주
  - 내 사이트로 전송받아 수정이 있으면 전송 후 갱신
  - 혹은 실제 필요한 부분만을 받아서 전송
- 연산 이주
  - 다수의 대형 파일에 접근하거나 정보가 필요할 때는 
    - 작업 지시 연산을 보내서 결과를 그냥 반환받기
- 프로세스 이주
  - 연산이주의 논리적 확장. 
  - 프로세스는 생성된 사이트에서만 실행되는 것이 아니라 자신의 일부 또는 전체를 다른 사이트에서 실행
  - 연산속도, 부하 공유, 통신 성능, 가용성, 특별한 기능의 이용
- 가장 대표적 예: 웹 (데이터 이주, 연산 이주)

### 분산 운영체제 설계시 고려사항

#### 통신방식
공유 메모리를 사용하지않아서, 분산 시스템을 위한 통신 기법이 있다.
- 메세지 전달
  - send, receive 두개의 기능
  - 송수신이 동기적이다.
    - 수신자는 receive를 실행하는 시점에서 메세지의 도착까지 기다리거나, 송신자가 수신자로부터 확인 메세지가 올 때까지 기다려야한다.
  - 공통의 자료표현방법이 있어야 한다.
- 원격 프로시저 호출
  - 메세지 전달 기법을 변형하여 개선했다. 
  - 클라이언트의 한 프로세스에서 서버의 프로시저를 호출할 경우, 관련정보들을 메시지로 묶어 서버로 전달하고 서버에서는 이 메시지를 원래의 형태로 풀어서 실행시키고 그 결과값들을 클라이언트에 돌려준다.
  - 통신 프로세스 간 인터페이스를 IDL로 정의하여 컴파일하면, 클라이언트와 서버 측에 각각 스터브 코드가 생성되고, 이는 공통의 데이터 표현형태로 변환하거나 다시 원래의 형태로 풀어내는 기능을 가진다.

#### 투명성
시스템 환경의 구체적인 부분을 사용자가 알 수 없게끔하거나, 사용자가 어떤 시스템이든지 로그인 할 수 있어야 한다는 개념

#### 확장성
분산 시스템의 규모가 커지는 경우에도 부하 증가에 적응할 수 있는 능력

#### 결함 허용
결함이 생겨도 기능을 계속 수행할 수 있어야한다.

#### 호환성
상호연동성이 시스템 구성 요소 간에 얼마나 보장되는지. 모든 호스트들이 같은 하드웨어 구조 및 기계어를 가져야하는 이진 레벨 호환성에서, 같은 통신 프로토콜을 갖는 가장 낮은 호환성까지 다양하다.

#### 이름 부여
여러 호스트에 분산되어 존재하는 객체들에 일관성 이/ㅆ는 이름을 제공하는 방법이 있어야한다. 

#### 서버 프로세스 구조
서버는 많은 클라이언트들이 동시에 서비스를 요구할 때, 효율적으로 운영되어야 한다. 

#### 전역 상태의 유지
병행성 문제. 통신 지연이 발생할 수밖에 없다. 
가상적으로 일관되게 유지하기 위해, 타임 스탬프를 이용한 이벤트 순서화기능이 필요하다.

#### 분산 상호배제와 교착상태
타임스탬프기법이 부여한 순서에 따라 처리한다. 

#### 분산 파일 시스템
파일시스템의 전통적 시분할 모델을 분산 환경으로 확장했다.
다수의 사용자들이 파일과 저장장치를 공유할 수있게 한다.

### 클라이언트/서버 시스템과 미들웨어
클라이언트 서버 접근 방식의 장점들이 모듈화 방식과 능력에 기반해, 상호 운영성 문제는 꼭 해결되어야한다.
이를 돕는게 미들웨어. 클라이언트가 여러 다양한 서버들에 일관된 방법으로 접근할 수 있게끔 지원한다. 

## 클러스터
고성능과 고가용성 제공. 여러 컴퓨터가 고속의 링크로 연결되어있고,
논리적으로는 하나의 컴퓨터인 것처럼 보여지게 자원을 일관되고 통일되게 관리한다. 
분산시스템과 비슷해보이지만 공유 디스크를 사용해 접근 성능을 더 높일 수 있다.

## 클라우드 컴퓨팅
정보처리를 자신의 컴퓨터가 아닌 인터넷으로 연결된 다른 컴퓨터로 처리한다.