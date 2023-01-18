논리를 배우는 이유? 논리적인 사고방식을 키우기 위하여. 설득하는 데 있어서 필요한 객관적 공유된 사실

### 논리의 규칙
- 수학적 의미
  - 수학적 진술에 정확한 의미 부여
  - 수학 주장의 유효성을 분별하는 데 사용
- 프로그래밍적 용도
  - 컴퓨터 회로 설계
  - 프로그램 작성
  - 프로그램 검증

## 명제
- 참 또는 거짓 중 하나로 판별 가능한 말
- 객관적으로 참 거짓 판별이 되지 않는다면 명제가 아니다. 

## 진리표
명제에서 나올 수 있는 참/거짓 판단의 모든 가능성을 표로 나열한 것.
여러 명제를 합친 결과를 볼 수 있어서 좋다.

## 합성 명제
- 단순 명제를 논리 연산자로 결합한 것들
- 조건 명제
두가지로 나뉜다. 

### 논리 부정
합성 명제를 알기위해 알아야 하는 것.

### 모든과 어떤의 부정
모든의 부정은 어떤
어떤의 부정은 모든.

## 논리곱
A And B
명제 p, q가 있을 때, 둘 다 참일 때만 참

## 논리합
명제 둘이 있을 때, 둘 중에 하나만 참이라도 참

## 배타적 논리합
XOR
p와 q 중에 하나만 참이면 참
그러나, 둘 다 참이면 안된다. 


## 언제나 참인 명제
p OR ~p = T
### 항진 명제
- 합성 명제 안의 단순 명제의 진릿값과 상관없이 언제나 참인 명제.

## 언제나 거짓인 명제
- 집합론에서 공집합 만드는 방법과 같다.
- p AND ~p = F
### 모순 명제
- 합성 명제 안의 단순 명제의 진릿값과 상관없이 언제나 거짓인 명제.

## 불 대수
boolean 대수
대수학 : 숫자를 대표하는 일반적인 문자를 사용, 수의 관계 성질 계산 법칙 따위를 연구하는 학문.

- 변수의 값으로 숫자 대신, 진릿값을 사용
- 논리학을 형식화하기에 적합.

- 디지털 회로 설계에 많이 사용.
  - 비트패턴 저장
- 프로그래밍 언어에서 사용
  - 조건식: 참/거짓
  - 논리연산: 여러 조건 결합

## 불 대수 조건식 집합론
- 집합의 연산 법칙과 불 대수 법칙은 매우 비슷하다.
  - 불진릿값: 집합이 요구하는 조건을 어떤 대상이 만족시키는지의 여부

### 불 대수의 기초 연산
T는 1로, F는 0으로

기호를 다른 것을 쓰기도 한다.


### 연산 우선 순위
1. not
2. and
3. xor
4. or

- 비트 연산이 논리 연산에 우선함
  - 비트연산: 2진수 값의 한 비트만 보면, 0은 거짓 1은 참이다.
  - 각 비트에 and, or, xor 연산을 하는 것과 마찬가지.


### 교환 법칙, 결합 법칙, 분배 법칙, 흡수 법칙
#### 교환 법칙
x+y = y+x
XY = YX

#### 결합 법칙
1. X + (Y+Z) = (X+Y) + Z
2. X(YZ) = (XY)Z

#### 분배 법칙
1. X(Y+Z) = XY + XZ

#### 흡수 법칙
1. X + XY = X
2. X(X+Y) = X

### 드 모르간 법칙
(X+Y)' = X' * Y'
- 프로그래밍하다보면 생각보다 매우 중요한 법칙
- if(!(age>=20 || height < 140))
- if(age<20 && height >= 140)

### 논리 회로
- 논리 연산을 통해 전기 장치를 제어하는 회로
- 컴퓨터 및 기타 전기 장치를 작동하게 만드는 기초 부품

#### 논리 연산
- 불 대수를 이용해서 설계

#### 게이트
- 논리 회로의 기초 구성요소
- 각 게이트는 불 연산 하나를 구현한다.
- 데이터 저장 기능은 없음.
- 각 게이트를 각 전자부품 가게에서 구매해 논리회로를 만들 수 있다.

#### NAND, NOR 게이트는 특별하다
N + AND
N + OR
- 둘로 다른 게이트를 모두 만들 수 있다. 그래서 범용 게이트라고 한다.

## 게이트의 조합
컴퓨터에 있는 모든 연산은 게이트를 조합해서 만든 것.
더하기 -> XOR
받아올리기 -> And


### 게이트는 돈이다!
- 연산 줄이는 법: 카노 맵으로.
- 

