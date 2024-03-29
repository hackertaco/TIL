컴퓨팅, 네트워킹 기술은 빠르게 발전하였지만, 적시에 적절하게 제공되지 않을 경우 불편을 초래하고, 정보가 유출되면 사회적 혼란을 초래할 수 이싿. 
이를 보호하는 기술이 필요하다.

## 보안의 개념
컴퓨터 시스템에 내장된 정보의 유출, 오용, 악용 등을 방지하고 네트워크를 통한 안전한 정보전달을 유지하는 행위

크게 암호 기술, 시스템 보안 기술, 네트워크 보안 기술로 나뉜다.
#### 암호기술: 암호 알고리즘, 암호 키 이용해서 평문 변환, 복호키 이용해서 평문으로 변환
#### 시스템 보안기술: 컴퓨터 내로 침임의 행위로부터 컴퓨터 자원 보호
#### 네트워크 보안 기술: 전산망을 통한 침입으로부터 무형의 정보를 보호하는 기술

이러한 침입이 자주 일어나는 이유
인터넷의 개방성, UNIX, TCP/IP 등의 소스 개방, 침입자들의 상호정보교환 용이

#### 보안의 목적
- 자료의 무결성: 자료 보호
- 자원의 가용성: 사용자가 서비스를 받지 못하게 하는 행위로부터 보호
- 정보의 비밀성: 접근이 허용된 사용자 혹은 프로세스만이 정보 취득하도록 보장

## 보안을 위협하는 유형
- 방해: 자원 가용성 위협. 시스템의 정상적 동작 방해
- 가로채기: 정보 비밀성에 대한 위협. 중요한 전산 자원에 접근하는 행위
- 수정: 정보 무결성에 대한 위협
- 위조: 정보 무결성 위협

## 보안 정책과 보안 메커니즘
유무형의 자원을 보호하는 관점에서 무엇을 어떻게 보호할지 명시하는 것
환경에 따라 다르지만, 대부분은 정책은 다음과 같이 짠다.
1. 각 사용자로 하여금 자신의 작업을 위해 꼭 필요한 최소정보만을 접근한다.
2. 임의 접근 제어 혹은 강제 접근 제어 정책
을 따른다. 

이 정책 실현을 위해 보안 매커니즘에서 다루는데, 일반적으로 Saltzer, Schroeder가 제안한 원칙이 많이 언급된다.
- 최소 권한
- 업무 분할
- 최소 공통
- 경제성 만족성
- 완전 중재
- 개방성
- 안정성

이를 위해 
- 인증
- 접근 제어
- 흐름 제어
- 감사
- 암호화 등의 매커니즘이 사용된다. 

### 암호 및 인증
1. 암호
- 가장 경제적, 효율적, 계층적 보안 대첵 제공
- 이를 사용하여 정보 내용의 불법적 노출 방지(정보의 보안), 합법적 수신자에 안전히 정보 전달(정보 인증), 상대방을 서로 확인하는 사용자 인증 목표를 지향

암호 시스템을 구성하는 기본요소: 암호 알고리즘
1. 암호화 키 = 복호화 키인 공통 키 암호 방식
2. 암호화키 != 복호화 키, 복호화 키 비밀리에 보관하는 공개 키 암호방식 두가지가 있다.

#### 공통 키/대칭 키 암호방식
송신자 수신자가 사전에 공통 키를 나눠가지고, 
송신자는 공통키로 평문을 암호화, 
수신자는 공통 키로 평문을 복호화한다.

계산량이 적지만 제 3자에게 도청되지않게 키를 전송해야하고, 모든 상대 통신자에 대해 비밀키 하나씩을 준비해야해서 키가 많아진다.
- DES가 대표적.
- 최근들어 해독된다. 검색 공간을 크게 하는 것

#### 공개 키/비대칭 키 암호 방식
가입자 전체가 암호화 키와 복호화 키 한쌍씩을 생성. 
암호화 키는 공개 파일에 등록, 복호화 키는 비밀리에 보관

키 종류가 많아지지않고 인증 기능을 가진다. 
계산량이 많아 고속의 연산기를 필요로 한다. 

송신자의 신원 확인이 어렵다.
대표적인 공개키암호시스템 예: RSA
평문의 암호화와 함께 디지털 서명 방식에서 자신의 서명을 수신자에게 안전히 전달하기 위해서 사용된다. 
소인수분해를 요구하는 암호 시스템의 해독은 현재까지는 충분한 시간 내에 해독할 수 없다.

#### 암호 해독
암호문을 평문으로 변환하려고 하는 제 3자를 침해자 혹은 암호해독자라고 한다.
이미 암호문을 알고있다고 전제했을 때, 암호문에서 비밀의 평문과 키를 찾을 수 있거나 또는 알려진 평문과 암호문으로부터 비밀키를 찾을 수 있는 경우 그 암호는 해독되었다고 한다.

기본적 공격형태는
- 암호문 만에 의한 공격: 가장 일반적 암호 해독법. 암호문만으로 비밀의 평문과 키를 찾는 가장 공격 어려운 방법
- 알려진 평문 공격: 암호문에 대응하는 평문을 알고있어, 그 지식을 이용해 비밀키를 찾아내고 그를 기반으로 평문을 찾는 방법
- 선택 평문 공격: 임의로 선택한 평문을 암호 알고리즘에 적용하여 암호문을 얻고, 그로부터 키를 찾는 방법

### 인증
- 특정 사용자가 합법적인지를 확인하는 제반 행위
- 오류 허용률과 오류 거부율을 합한 값이 낮을수록 정확한 인증 작업을 하는 것.
  - 오류 허용률: 인증받으면 안되는 사용자 잘못 인증
  - 오류 거부율: 인증받아야하는 사용자 거부

#### 패스워드 사용 인증
가장 보편적. 특별한 하드웨어 사용하지않고, 미리 사용자가 설정한 패스워드를 기억한다
완벽한 보안을 기대하긴 어렵다. 
동일한 사용자의 인증 시도를 제한한다

#### 물리적 기반 인증
칩을 내장한 스마트 카드 등을 이용. 추가 비용의 부담.

#### 생체인식 기반의 인증
사용자의 유일한 특성에 기반. 개인프라이버시 침해 문제가있음

