# Database
- 특정 조직의 여러 사용자가 공유하여 사용할 수 있게 통합해서 저장한 운영 데이터의 집합

## 특징
- 실시간 접근 가능
- 계속 변화
- 동시 공유가 가능
- 저장된 주소가 아닌 내용으로 참조가 가능

## 저장되는 데이터 유형
- 정형 데이터: 흔히 사용하는 
- 반정형 데이터: meta정보에 어떻게 데이터가 저장되는지 적혀잇음
- 비정형 데이터: 

## 기존 파일 시스템의 문제
- 데이터 중복성 문제
- 업데이트 및 데이터 일관성 유지 어려움
- 데이터 무결성 유지가 어려움
- 데이터 종속성: 응용프로그램이 파일 데이터 구조에 종속적, 파일구조가 바뀔때마다 응용프로그램 교체가 필요
- 동시성 제공이 어려움: 동시에 접근할 때 문제 해결 어려움
- 원자성 제공 어려움 -> 파일 변경 중에 시스템 장애가 발생했을 때 처리 어려움
- 보안 제공 이슈 -> 일부 데이터 읽기 권한 제어가 어려움..

## 극복! DBMS
응용프로그램과 데이터 연결을 돕는다. 

# DBMS
파일 시스템 문제를 해결하기 위한 소프트웨어

### 주요 기능
- 정의 기능: 데이터베이스 구조 정의하거나 수행. 언어를 통해 테이블 정의하고 구조 만듦
- 조작 기능: 삽입 삭제 수정 검색 연산
- 제어 기능: 데이터를 항상 정확하고 안전하게 유지하는 기능 (접근권한, 백업같은)

### 주요 장점
- 기존 파일 시스템의 문제를 해결해준다
- 응용 프로그램 개발 비용이 줄어듦
- 데이터 구조가 바뀌어도 프로그램이 바뀔 필요가 없다

### 주요 단점
- DBMS 구매 비용
- 응용 프로그램이 DBMS를 통해 데이터에 접근해서, 추가적 오버헤드
- 응용 프로그래머의 지식 필요 (잘 짜야한다.)
- 장애가 발생할 때 모든 응용프로그램 장애 발생 

### Data Dictionary
- 데이터베이스와 함께 메타데이터를 저장한다.
- 데이터 정의어에 의해 생성된다.

### Metadata
- 각 데이터에 접근 가능한 데이터 이름이나
- 데이터 저장된 위치
- 여러 제약 등이 있다.

# 데이터베이스 시스템 구조

DBMS+ 응용프로그램 모두를 통칭한다.

## 스키마
- 데이터베이스에 저장되는 데이터의 논리적 구조와 제약조건

## 인스턴스
- 스키마에 따라 데이터베이스에 저장된 값

## 3단계 데이터베이스 구조
가장 많이 사용되는 구조
External, Conceptual, Internal Schema로 나눔

### 가장 가까운 (db와) 내부 스키마
- 실제 데이터가 데이터베이스에 어떻게 저장되는지 기술
- 파일에 저장되는 레코드 구조 

### 개념 스키마
- 일반적인 스키마
- 개념적으로 표현 관계 기술
- 물리적 데이터 독립성

### 외부 스키마
- 사용자에게 view의 형태로 필요한 정보만 보여주는 단계 

# 데이터베이스 시스템 언어
- 데이터베이스를 설계 및 구축, 제어

- 사용자가, 데이터 베이스 언어를 이용할 수도 있고(캐주얼 엔드유저), 응용 프로그램을 통해 할 수도 있다. (네이티브 엔드유저)

## 데이터 정의어(DDL)
> 스키마 구조와 제약조건 등을 정의 삭제 수정

## 데이터 조작어(DML)
> 데이터의 삽입 삭제 수정 검색

## 데이터 제어어 (DCL)
> 데이터베이스 백업이나 회복하는 명령어


### DDL Interpreter
- ㅇ스키마 정의 해석, 데이터 딕셔너리

### DML Compiler
- 데이터 처리 요구를 프로세스 엔진이 이해할 수 있는 코드로 해석하여 플랜 작성

### DML Processing Engine
- 컴파일된 플랜을 데이터베이스에 실제로 실행