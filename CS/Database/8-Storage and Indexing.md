Disk 액세스는 DBMS의 성능에 가장 주요한 문제가 된다.

- READ: 디스크에서 메인 메모리에 데이터를 전송하는 것
- WRITE: 메인메모리에서 디스크로 데이터를 전송하는 것!

효과적인 메모리-디스크 데이터 전송위해 버퍼 관리가 필요하다. 

디스크 액세스 작업은 비용을 초래해서, in memory database라는 것도 있다. 

### Disk Space management
- DBMS에서 가장 낮은 레이어에서 디스크 공간 관리
- 디스크 컴포넌트에 페이지를 할당하고, read, write page
- 랜덤 액세스가 성능이 가장 안 좋다. 페이지들이 최대한 연속적이도록 디자인 해야한다. 
  - seek, rotation delay 줄이기

page offset > page id 전달 > 디스크에서 페이지를 읽고 > buffer free frame 찾아서 넣기 > pin/unpin reclaim > unpin들 중에 프리 프레임이 없을 때 이뤄진다.

- LRU: 가장 최근에 사용되지않은 경우에!

### 버퍼 관리
- pool에서 프레임 선택
  - 프리프레임 선택
  - 없으면 LRU에 의해 오래된 프레임 unpin
- page를 디스크에서 읽어서 프레임에 저장한다. 
- pin_count++, page를 사용하는 사용자 있음 표시
- 주소를 반환

페이지 사용 끝나면 unpin 
-  만약 업데이트 된 경우 dirty flag를 표시

페이지 리스트 예상이 되면 prefetch! async하게 채워지게 된다. 

### 어떠한 형태로 저장되는가?
- Fixed length
  - field type, size 정보가 시스템 카탈로그에 저장.
  - 사이즈를 알아서, 레코드 주소 빠르게 반환 가능하다.
  - packed format
    - 레코드가 지워지게 되면, 그 자리를 사용하기 어렵다. delete 가능 구조에서는 별로다.
  - unpacked format
    - free space 슬롯 넘버를 확인하여, 프리 스페이스를 allocate 가능하다.
- 대부분은 Variable Length
  - 따로 표기를 주어서, 해당 표기를 찾아서 장소를 찾거나
  - offset을 앞에서부터 계산해서 포인터로 장소를 찾아가는 것.
    - 이 경우, 서로 반되되게 포인터와 레코드를 배치한다. 
    - rid가 고정되어 레코드 옮겨도 ㄱㅊ다.


## 인덱스 개념
스토리지에서 인덱스가 어떻게 구성돼있을까? 

- rows를 빠르게 찾기위해 사용.
- 인덱스에 대한 page가 저장이되는 것
  - 서치 성능 향상
  - 인덱스 관리하는 비용이 발생한다. -> DML 성능 저하
  - 인덱스를 저장하기 위한 space 사용 증가.
- 인덱스에서 검색을 위해 사용되는 column , column의 집합을 서치키라 한다.
  - 한 테이블에서 다른 서치 키를 가지는 수많은 인덱스 생성 가능


### 고려 사항?
- 언제 사용될 것인가?
  - 정확하게 일치하여야하는지
  - 범위 쿼리에 사용할 예정인지?
  - 모든 row 용인지?
- 얼마나 테이블이 자주 업데이트 되는지?
- 인덱스의 키가 슈퍼키인지 프라이머리 키인가?
- 하나의 키로 여러 row가 가능한가?

### Tree vs Hash Index
- Tree Index는 서치키의 순서로 인덱스 엔트리 정렬
  - 차례대로 작업할 때 유리, 
  - b+ Tree에 사용
- Hash Index
  - index entry위치를 버켓의 위치를 지정해서 빨리 찾는다.

## B+ 트리 인덱스
- 바이너리 트리랑 비슷한 구조인데, 모든 leaft 모드에 key와 데이터 포인터 저장.
- 컴포넌트
  - 루트
  - non-leaf
  - leaf
- 차수 n은 노드 사이즈를 결정한다
  - n+1pointers+n key

### Insert
- Leaf Node에 공간이 있는 경우
- 없는 경우 overflow
  - 쪼갠다
- non leaf overflow case
  - 불필요한 빈 노드를 많이 만들지 않기 위해 
    - 논리프: n+1/2개가 넘지않는  포인터
    - 리프: n+1/2이상의 포인터
- 새로운 루트 케이스

### Delete
- Lead Node
  - 떨어져있는 걸 합치기도 한다. 
- Redistribute key 
- Non-leaf coalesce


## Hash Index
Index들이 버킷이라는 단위로 저장되고, 
- 버킷을 고정된 수로 할당하는 것이 static hashing
- 데이터 양에 따라 가변적으로 버킷이 늘어나는 것이 dynamic hashing

### static hashing
- 버킷 수가 정해져 있어서 overflow 발생 가능.
- 오버플로우가 나타나면 링크드리스트 형태로 같은 해시키를 갖는 버킷 연결

### dynamic hashing
- 버킷 수 동적 변경.
- 해싱 함수 결과를 binary로 표현하여 prefix를 사용 
- 키를 가지고 바로 엔트리 찾을 수 있다. 
- 정렬은 안된다. 
- 키 값은 고정. 버킷수를 prefix로 변경 가능하다. 