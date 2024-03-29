MySQL => 머리 역할
스토리지 엔진 => 손발 역할

## MySQL 엔진 아키텍처
### MySQL 전체 구조
#### MySQL 엔진
- 클라이언트로부터의 접속 및 쿼리 요청을 처리하는 커넥션 핸들러
- SQL 파서 및 전처리기
- 옵티마이저
#### 스토리지 엔진
실제 데이터를 디스크 스토리지에 저장하거나, 데이터를 읽어오는 부분은 스토리지 엔진이 전담

#### 핸들러 API
MySQL의 쿼리 실행기에서 데이터를 쓰거나 읽어야할 때, 스토리지엔진에 요청한다. 
이를 핸들러 요청이라 한다.

### MySQL 스레딩 구조
프로세스 기반이 아닌 스레드 기반으로 작동.
포그라운드와 백그라운드로 구분한다.

#### 포그라운드 스레드
MySQL 서버에 접속된 클라이언트 수만큼 존재한다. 
클라이언트 사용자가 요청하는 쿼리 문장을 처리한다. 

작업을 마치고 커넥션을 종료하면 스레드는 스레드 캐시로 돌아간다. 
포그라운드 스레드는 데이터를 MySQL 버퍼나 캐시로부터 가져오고, 없으면 직접 디스크의 데이터나 인덱스 파일로부터 읽어온다. 
InnoDB의 경우 버퍼나 캐시는 포그라운드가 처리. 나머지 버퍼로부터 디스크 기록은 백그라운드 스레드가 처리

#### 백그라운드 스레드
쓰기 작업을 버퍼링해서 일괄처리한다. 
- 인서트 버퍼를 병합
- 로그를 디스크로 기록
- 버퍼 풀의 데이터를 디스크에 기록
- 데이터 버퍼로 읽어오는 
- 잠금이나 데드락 모니터링
- 이 모두가 InnoDB에서는 백으로 처리된다. 

### 메모리 할당 및 사용 구조
글로벌 메모리 영역/로컬 메모리 영역으로 구분한다.
글로벌 메모리 영역과 로컬 메모리 영역은 많은 스레드가 공유해서 사용하는 공간인지 여부에 따라 구분된다.

- 글로벌: MySQL 서버 시작시 운영체제로부터 할당된다. 
  - 요청 메모리 공간을 100% 할당할 수도 있고, 기간을 나눠 할 수도 있다.
  - 스레드 수와 무관, 하나의 메모리 공간만 할당된다. 
  - 모든 스레드에 의해 공유된다
  - 테이블 캐시, 버퍼 풀, 해시인덱스, 로그버퍼
- 로컬: 세션 메모리 영역이라고도 표현. 
  - 클라이언트 스레드가 쿼리 처리에 사용한다.
  - 각 클라이언트 스레드별로 독립적 할당. 공유되지않는다. 
  - 쿼리 용도별로 필요할 때만 할당되고 필요없으면 할당하지않을수도 있다.

### 플러그인 스토리지 엔진 모델
스토리지 엔진만 플러그인을 하지느 ㄴ않고, 검색어 파서 같은 것도 개발해서 사용 가능하다. 
그리고 대부분은 mysql엔진에서 실행되므로, 일부분의 기능만 수행된다. 
그렇다고 할지라도, 스토리지 엔진의 영향은 크다 (읽기/쓰기)

MySQL 서버에 포함되지 않은 스토리지 엔진을 사용하려면 서버를 다시 빌드해야한다. 

### 컴포넌트
8.0버전부터 기존의 플러그인 아키텍처를 대체하기 위해 컴포넌트 아키텍처가 지원된다. 
기존 플러그인의 단점은
- MySQL 서버와만 인터페이스가 가능. 플러그인끼리 불가
- 캡슐화 안됨
- 상호 의존 관계 설정이 어려워 초기화 어렵다.

이를 컴포넌트가 개선한다.

### 쿼리 실행 구조
#### 쿼리 파서
사용자 요청으로 들어온 쿼리 문장을 토큰으로 분리. 트리 형태의 구조로 만들어낸다. 
쿼리 문장의 기본 문법 오류를 여기서 발견한다.

#### 전처리기
파서 트리 기반으로 쿼리 문장에 구조적 문제가 있는지 확인한다. 
문장 내 컬럼 이름, 내장 함수 등의 개체와 매핑, 객체 존재 여부 파악한다.

없으면 이 단계에서 걸러진다.

#### 옵티마이저
사용자의 요청으로 들어온 쿼리 문장을 저렴한 비용으로 가장 빠르게 처리할지를 결정하는 역할
두뇌와 같다. 매우 중요하다.

#### 실행 엔진
손과 발에 비유할 수 있다. 만들어진 계획대로 핸들러에게 요청해서 받은 결과를 또 다른 핸들러 요청의 입력으로 연결하는 역할을 수행한다.

#### 핸들러
서버의 가장 밑단에서 실행 엔진의 요청에 따라 데이터를 디스크로 저장하고 읽어온다. 
스토리지 엔진이다.

#### 복제
추후 다룰 예정

### 쿼리 캐시
빠른 응답을 필요로 하는 웹 기반 응용프로그램에서 매우 중요한 역할 담당.
SQL 실행 결과를 메모리에 캐시, 동일 SQL 쿼리가 실행되면 테이블 읽지않고 즉시 결과를 반환. 매우 빠른 성능을 보인다.
하지만 테이블 데이터가 변경되었을 때, 해당 변경 테이블과 관련한 데이터는 모두 삭제해야해서 동시 처리 성능 저하로 이어졌다.

그래서 8.0에서는 해당 기능이 삭제되었다.

### 스레드 풀
내부적으로 사용자의 요청을 처리하는 스레드 개수를 줄여, 동시 처리되는 요청이 많다 하더라도 MySQL CPU가 제한된 스레드 처리에만 집중하게 해서, 서버의 자원 소모를 줄인다.
실제 눈에 띄는 성능향상은 드물고, 
동시에 실행 중인 스레드들을 빨리 처리하게 하는 기능이라, 스케줄링에서 CPU 시간을 제대로 확보하지 못하면 쿼리 처리가 더 느려진다.

### 트랜잭션 지원 메타데이터
테이블 구조 정보, 스토어드 프로그램 등의 정보를 데이터 딕셔너리 혹은 메타데이터라고 한다. 
그러나 파일 기반의 메타데이터는 생성 및 변경 작업이 트랜잭션을 지원하지 않아, 테이블의 생성 또는 변경 도중에 서버가 비정상 종료했으면 일관되지 않은 상태로 남는 문제가 있었다. 

따라서 8.0버전은 이를 InnoDB의 테이블에 저장되도록 했다. 이는 트랜잭션 기반이라 중도에 비정상 종료가 되어도 스키마 변경이 완전한 성공 혹은 실패로 정리된다. 

그런데 InnoDB 이외에는 여전히 메타 정보를 저장할 공간이 필요하다.(MyISAM, CSV)
그를 위해 SDI 파일을 사용한다. 이는 기존의 메타데이터 저장하던 (.FRM)과 동일하다. 
