1. 선언적 언어! 뭘 원하는지는 말하고 어떻게 할지는 이야기하지않는다. 
2. 다양한 효율성과 완성 기준
3. 확장성이 있는 언어
4. 튜링완전성 언어가 아니다. 제한이 없다.

### SQL에 사용되는 모델? 
릴레이션에는 스키마가 있고, 인스턴스가 있다. 스키마를 만족한다. 
- 속성은 컬럼이고 필드다
- 튜플은 레코드고 로우다.
- 잘 정의된 쿼리 언어다. 

- 스키마는 정해져있다. 속성명은 다 다르게 만들어져야한다. 
- 인스턴스는 잘 바뀐다. 로우의 멀티셋이다. 
- 테이블 내용은 원자적이어야한다. 

### RDBMS는 sql의 효율성을 평가해야한다. 
적절한 알고리즘을 택해야한다.

### 기본키는 한개 이상의 컬럼으로 만들어질 수 있다. e.g (firstname, lastname)

### 외래키는 스키마에 있어서 포인터와 같은 것이다. 

### Aggregates -> Batch of Tuples를 계산! 

### FROM Clause -> WHERE -> Group By -> Having -> Aggregate -> Order by 순서로 compute

### join
여러 테이블들의 연산. 주된 차이점은? from clause에 여러 릴레이션이 있다는 것.

### Aliases
self join에도 해당 AS가 사용된다. 

### Like보다는 정규형

### ARGMAX는 그룹이 지어져있어야. 

### inner join
infix notation, 