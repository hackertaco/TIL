개념적 데이터 모델:: 현실 세계의 상황과 조건을 개체/속성/관계 집합으로 추상적 표현
즉, 복잡한 현실을 단순화하였다.

- ER 모델이 대표적
  - 이는 개체, 속성, 개체 집합 간의 관계 집합을 표현한 것이라, 집합이 뭔지부터 알아야한다.
## 집합이란? 
어떤 주어진 조건에 의해, 그 대상을 분명히 알 수 있는 것들의 모임
- 원소는 그 집합을 구성하는 대상 하나 

## ER 모델
개체는 직사각형, 타원은 속성, 마름모는 관계 

---

# ER모델의 구성요소
## 개체
유형의 정보를 가지고 현실세계에 물리적으로 존재하는 실체 
혹은 무형의 정보를 가지고 추상적, 개념적으로 존재하는 실체

- 독립적으로 존재
  - 각 이름을 가지고 있다. 
  - 각 개체만의 고유한 특성을 나타내는 속성을 하나 이상 가지고 있다. 
- 발생 시점에 따라 기본 개체, 중심 개체, 행위 개체로 구분 가능하다
  - 기본 개체는 원래 업무에 존재하는 정보다. 다른 개체의 부모 역할을 한다.
  - 중심 개체는 기본 개체에서 발생하고 데이터 양이 많다. 다른 개체와의 관계를 통해 행위 개체를 생성하기도 한다. 
  - 행위 개체는 두 개 이상의 부모 개체에서 발생된다. 데이터 양이 증가한다. 내용이 빈번히 변경된다
    - 따라서 분석 초기에는 잘 나타나지 않을 수 있다. 
  - 이 개체 분류를 명확히 하면 업무 분석에 효과적이다. 
- 개체 타입은 직사각형으로 나타낸다. 단수형 명사 사용한다. 
  - 강한 개체 타입과 약한 개체 타입 종류가 있다.
    - 강한 개체 타입은 다른 개체의 도움없이 독자적으로 존재한다.
    - 약한 개체 타입은 반드시 상위개체 타입을 가진다. 이 때 두 줄로 이루어진 직사각형으로 표시한다.

### 개체 인스턴트란 개체를 구성하는 속성들이 실제 값, 데이터를 가져 실체화된 형태의 개체를 말한다. 
### 개체 집합이란 이 같은 속성을 가진 개체 인스턴스들이 모인 것을 말한다. (릴레이션 외연)
### 개체 타입이란 개체 인스턴스의 틀을 말한다 (릴레이션의 내포)


## 속성
개체의 특성이나 상태를 구체적으로 기술한다.
속성값이란 개체의 특성이나 상태가 현실화된 값이다. 
- 타원으로 표시
- 개체타입에 실선으로 연결
- 단수형 명사 사용
- 식별자: 다른 개체 인스턴스와 구별할 수 있게 하는 하나 또는 그 이상의 속성. 기본키같은 것. 밑줄을 그려 표시
- 설명자: 개체를 설명하기 위해서만 존재하는 속성
- 복합속성: 독립적인 의미를 가진 몇 개의 기본적인 단순 속성으로 분해 가능한 속성. ex) 이름은 성과 이름으로 다시 분해 가능
- 다중값 속성: 하나의 속성이 여러개의 속성값을 가진다. 이중선으로 표시한다
- 유도 속성: 다른 속성이나 개체가 가지고 있는 값으로부터 유도되어 결정되는 속성 값. 이에 사용되는 속성을 저장속성이라 부른다. ex) 나이는 현재 날짜에서 생년월일을 빼면 구할 수 있다.
  - 점선으로 표시한다.

## 관계 
개체와 개체가 맺는 의미있는 연관성.
- 마름모로 표현
- 관계 타입이 관련된 개체 타입에 실선으로 연결
- 단수형 명사

### 관계 타입: 개체 타입과 개체 타입 간의 연결 가능한 관계를 정의한다.
### 관계 인스턴스: 관계가 현실화된 형태. 하나의 관계 타입에는 여러 개의 관계 인스턴스가 존재할 수 있다.
### 관계 집합: 특정한 관계 타입에 여러개의 관계 인스턴스 모아 놓은 것

- 관계의 차수 특성: 특정한 관계에 연결된 개체의 개수가 관계의 차수. 1차 ~ n차 가능. 그러나 보통 2차가 흔하다.
  - 3차 이상은 보통 2차로 변환하는데, 주의를 기울여야한다.
- 관계의 카디널리티 특성: 하나의 관계에 실제로 참여할 수 있는 인스턴스의 수를 의미한다. 모델링하려는 현실세계의 시나리오로부터 유도된다. 
  - 1:1: 관계에 참여하는 각각의 인스턴스가 다른 인스턴스에 단지 하나의 관계만을 가지는 것.
  - 1:n: 관계에 참여하는 각각의 인스턴스는 다른 인스턴스에 대하여 하나 이상의 관계를 가지나, 반대 방향으로는 단지 하나의 관계만을 가지는 것. ex. 출판서와 도서 사이
  - n:m: 집합 하나의 원소들이 다른 원소 여러개와 관계를 맺을 수 있다. 
- 관계의 참여 제약 조건 특성
  - 개체 집합에 포함된 모든 개체 인스턴스가 관계에 필수적으로 참여하는 관계를 의미하는 전체 참여와, 일부만 참여하는 관계를 의미하는 부분 참여로 구분 가능하다. 
    - 전체 참여는 두줄
    - 단일 참여는 한줄

