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


## DDL
1. Create Schema
    > CREATE SCHEMA 스키마명 AUTHORIZATION 사용자 id
2. Create Domain
    > CREATE DOMAIN SEX CHAR(1) DEFAULT 기본값 CONSTRAINT 제약조건명 CHECK (VALUE IN ('남','여'))
3. Create Table
    > CREATE TABLE 테이블명 (속성명 데이터 타입 NOT NULL), PRIMARY KEY(속성명) REFERENCES 참조 테이블(속성명)
4. Create View
    > CREATE VIEW 뷰명 AS SELECT 
5. Create Index 
    > CREATE INDEX 인덱스명 ON 테이블명(속성명)
6. ALTER TABLE
    > ALTER TABLE 테이블명 ADD, ALTER, DROP COLUMN

## DCL
1. GRANT / REVOKE
   > GRANT 사용자 등급 TO 사용자_id_리스트
   
   > REVOKE 사용자 등급 FROM 사용자_id_리스트
2. COMMIT: 트랜잭션 처리가 정상적으로 완료된 뒤 트랜잭션이 수행한 내용을 데이터베이스에 반영하는 명령어
3. ROLLBACK: 변경되었지만 COMMIT 되지는 못한 모든 내용들을 취소 후 데이터베이스를 그 시점으로 돌리는 명령어
4. SAVEPOINT: 트랜잭션 내에 롤백할 저장점을 지정하는 명령어

## DML
