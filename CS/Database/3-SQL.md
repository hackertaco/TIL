- IBM 
- SEQUEL개발. 

이후 SQL로 이름이 바뀜

새로운 것이 추가될 필요가 있을 때 표준을 논의
- 대부분의 DBMS는 SQL-92 표준의 대부분을 지원.
- 최근 SQL-2011에 추가된 기능 예제
- Temporal table 변경 내용을 기억하면서 타임테이블 가능한! 

## SQL 분류
1. DDL: 테이블 생성, 변경, 제거
2. DML: 테이블 새 데이터 삽입, 수정, 삭제
3. SELECT: 데이터 조회
4. DCL: 보안을 위해 데이터 접근 및 사용권한 조절

## 관계대수와 다른 것
- Relation > Table
- Tuple > Row
- Attribute > Column
- Relational schema > Table schema

### Dbeaver : 데이터 베이스 관리 도구

## DDL
- CREATE: 데이터베이스 오브젝트들을 생성
- ALTER: 존재하는 오브젝트의 정의를 변경
- DROP

1. CREATE
> CREATE TABLE 

### 데이터 타입
- CHAR(n) = 길이 고정된 문자열
- VARCHAR(n) = 최대 길이가 n인 가변 길이의 문자열
- BigInt/INT/SMALLINT : 8/4/2바이트 정수
- BLOB/CLOB : 큰 데이터 타입! 
- default value라는 개념도 있다. > 만약 Insert에서 넣지않았을 때, 디폴트 값을 표현


### constraint clause
- integrity constraint => UNIQUE, primary key, reference constraint, check constraint

## 기존 테이블로 새 테이블 만들기
>CREATE TABLE {table name} LIKE {another table} WITH DATA : 다른 테이블 거를 다 카피


2. ALTER
- 새 컬럼을 추가
- 기존 컬럼을 삭제
- 새로운 제약 조건을 추가
- 제약조건을 삭제

3. DROP
- TABLE 삭제
---
# SELECT문
- SELECT + WHERE (조건)
- LIKE keyword (%, _) : BLOB, CLOB에는 안 돈다.

## NULL value
- 산술 연산 및 비교 연산 결과 null

## ORDER BY 
- 검색 결과 정렬

## Aggregation Function 
- COUNT, MAX, MIN, SUM, AVG
- cOUNT MAX MIN은 LOB 타입 제외하고 사용 가능
- SUM, AVG는 숫자에만
- NUll이면 무시, Count이면 모든 컬럼 null일시 0 리턴

## JOIN 
- Natural join을 많은 dbms가 지원안한다.

# DML
## INSERT
INSERT VALUES
- INSERT INTO 뒤에 다른 테이블에서의 질의 결과를 삽입 가능.

## DELETE
DELETE FROM 

## UPDATE
UPDATE SET 
