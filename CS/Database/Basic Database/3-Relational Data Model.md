### 테이블 구조는 사람들이 현실 세계의 데이터를 직관적으로 쉽게 이해하는 데 도움을 준다.

이 테이블을, 관계형 데이터 모델에서는 릴레이션이라고 부른다. 
릴레이션은 수학에서 유래된 개념이다. 수학 집합 개념에서, 릴레이션은 두 개 이상의 집합으로부터 각 집합을 구성하는 원소들의 순서 쌍을 의미한다.

## 릴레이션 관련 용어
- 릴레이션의 열 = 속성
- 릴레이션의 행 = 튜플
- 도메인 = 하나의 속성이 가질 수 있는 모든 타입의 집합.
  - 각 속성의 도메인은 원자값을 가진다. 
  - ER 모델의 복합 속성이나, 다중 값 속성은 허용되지 않는다.
- 특정 속성 값을 알 수 없어서 입력이 불가하면 NULL

## 릴레이션 스키마와 인스턴스
요구조건의 정의에 따라 만들어진 데이터 구조를 릴레이션 스키마, 혹은 스키마라고 한다. 
- 한 개의 릴레이션의 논리적인 구조를 정의한 것 = 릴레이션 스키마
- 릴레이션 이름(_속성명1_, 속성명 2 ....) 기본키 아래에는 밑줄
- 릴레이션 속성 수를 차수(degree)라 칭함

이렇게 릴레이션 스키마에 실 데이터를 넣은 것을 릴레이션 인스턴스, 혹은 인스턴스라고 한다. 
이 인스턴스의 튜플 수를 카디날리티라고 한다. 

## 릴레이션의 특성
1. 튜플의 유일성: 하나의 릴레이션 인스턴스 내에서는 서로 중복된 값을 가질 수 없다. 
2. 튜플의 무 순서: 하나의 릴레이션에서 튜플 간의 순서는 의미가 없다. 
3. 속성의 무순서성: 속성도 마찬가지로, 속성이 같으면 순서는 관계 없다.
4. 속성의 원자성: 모든 속성 값은 원자값만 사용 가능하다.

## 무결성 제약조건
### 키
무엇인가를 식별하는 고유한 식별자 기능을 하는 키. 

### 릴레이션 키
- 슈퍼키: 하나의 릴레이션을 구성하는 속성들 중에서 튜플을 **유일하게** 식별할 수 있는 하나 또는 그 이상의 속성들의 집합이다. 
  - 튜플을 고유하기 구별하는 데 꼭 필요치않은 속성들도 포함 가능. 
  - 키를 구성하는 속성이 많으면 복잡해지니까, 최소로 유지할 필요
- 후보키: 각 튜플을 유일하게 식별 가능한 최소한의 속성들의 집합이다.
  - 슈퍼키 개념에 최소성 기준도 포함된 것.
- 기본키: 여러 후보키 가운데, 하나를 선택하여 튜플 식별기준으로 삼음.
  - 튜플을 유일하게 구별할 수 있어야 해서, NULL이나 중복된 값을 가질 수 없다. 
- 대체키: 기본키 설정하고 남은 후보키
- 외래키: 단일 릴레이션 말고, 릴레이션끼리의 관계와 관한 키. 어떤 릴레이션의 기본키를 참조하는 속성. 릴레이션의 기본키와 동일한 도메인을 가져야한다. 

### 무결성 제약조건
데이터베이스의 정확성을 지키기 위해 만족해야하는 조건. 일관성 조건을 오직 한번만 명시하면, 데이터베이스가 갱신될 때 DBMS가 자동으로 일관성 조건을 검사한다.
- 개체 무결성 제약조건: 릴레이션에서 기본키를 구성하는 속성은 Null이나 중복값을 가질 수 없다. 
- 참조 무결성 제약조건: 릴레이션 간의 참조 관계를 정의하는 제약조건. 관련 릴레이션의 일관성 유지에 사용된다. 
  - 참조되는 릴레이션: 부모 릴레이션
  - 참조하는 릴레이션: 자식 릴레이션이라고 칭하면, 
  - 참조 무결성 제약조건은 두가지중 하나의 조건을 만족해야한다. 
    - 외래키 값은 부모 릴레이션의 어떤 튜플의 기본키 값과 같다.
    - 외래키가 자신 릴레이션의 기본키를 구성하는 게 아니면 NULL 값을 가진다.
    