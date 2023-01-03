# External level
- 사용자가 보는 뷰레벨

## View 의 목적
- 어떤 경우에 모든 사용자가 전체 논리적 모델을 보는 것은 문제가 될 수 있다. 
- 필요한 데이터만 보여줄 때
- 질의문 작성을 쉽게 만들어준다.
- 데이터 종속성을 제거

## View 정의
- Create View {view-name} {column_name_list} as {query expression}

### Updatable View
- View에 대한 삽입, 수정, 삭제 연산도 가능
- 베이스 테이블이 하나인 경우 가능(조인 안됨)
- Select clause에 컬럼 이름만 있는 경우

### Materialized View
- View에 대한 계산이 복잡한 경우, 미리 결과를 계산하여 쿼리 성능을 높임.
- 실시간으로 업데이트는 안된다는 단점이있다.
- 그래서, on-demand mode/real-time mode로 refresh 방법을 제공

### Drop View
- View만 삭제하는 것

# 트랜잭션 SQL

## Transaction
- 논리적인 작업의 단위
- 원자성: 트랜잭션 연산이 모두 실행이 되거나 혹은 하나도 안되거나 한다. 실패하면 롤백한다.
- 일관성: 트랜잭션 전후에 일관성있는 데이터베이스 상태로 유지되어야한다. 조건 어기면 트랜잭션 실패
- 격리성: 트랜잭션 수행시 다른 연산 작업이 끼어들지 못하게 보장한다. 
- 지속성: 성공적으로 수행된 트랜잭션은 영원히 반영되어야 한다.

- 모드: 
  - Autocommit: default, 매 statement 끝에 commit이 자동으로 실행된다. 
  - Explicit: start, commit, rollback -> 하나의 트랜잭션에서 작업하고 싶을 때.

- isolation level
  - Read Uncommited : 처리 중에 데이터 읽는 거 허용, 일관성 유지 안된다.
  - Read Commited: 커밋된 레코드만 볼 수 있다. 대부분 이걸 많이 사용, 한 트랜잭션 안에서 같은 Selection이 있을 때 조회가 다를 수 있다.
  - Repeatable Read: 트랜잭션 안에서의 같은 조회는 항상 동일한 결과가 리턴하는 것을 보장한다. 업데이트 문에서는 영향 받는다. 
  - Serializable: 완벽한 읽기 일관성 모드 제공
  
# 무결성 제약 조건

## Create Table
- Not Null
- Primary key
- Unique
- Check (p): 특정 속성 값의 도메인을 check 키워드를 사용하여 지정할 수 있다.

## 참조 무결성
- 관계 데이터베이스 관계 모델에서 테이블 간의 일관성을 유지하는 것
- 외래키를 지정
- ON DELETE {option}, ON UPDATE {option}

# DCL
- Authentication : 계정을 가진 사용자가 접속할 수 있게 해주는 접근 제어
- Authorization : 접속한 사용자의 사용 범위와 권한을 정의하는 것.

- Grant를 통하여 줄 수 있다.
- with grant option은 내가 받은 권한을 다른 이에게도 줄 수 있는 것.
- REVOKE를 통해 준 권한 취소 가능. (CASCADE, RESTRICT)
- ROLE을 만들 수 있다.