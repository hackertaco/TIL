## 01. Access List
네트워크에 접근을 시켜줄까 말까를 미리 정해둔 리스트다. 
주로 보안을 위해 사용된다. 라우터에도 세팅해두면, 네트워크 계층까지 관리해준다.

### 종류
1. 스탠더드: 가장 기본적인 액세스리스트. 출입 통제 시 출발지 주소만 참고한다. 
2. 익스텐디드: 스탠더드보다 조금 더 복잡하다. 출발지, 목적지, 프로토콜, 사용 포트 모두를 확인한다. 
3. 다이내믹: username, pw에 따라 통제가 가능하다. 

만약 액세스리스트에 걸려서 못 들어가는 경우, **Host Unreachable** 이라는 메세지를 받는다. 

## 2. AC에서 중요한 규칙들
1. AC는 윗줄부터 하나씩, 차례로 수행된다.
2. AC 마지막 라인에 'permit any'가 없으면 default로, 어느 AC와도 매칭되지않은 나머지 모든 주소는 deny된다.
3. AC의 새 라인은 항상 맨 마지막으로 추가되므로, accesslist-line의 선택적 추가나 삭제가 불가하다.
4. 인터페이스에 대한 AC가 정의되지 않은 경우, 결과는 permit any가 된다. 

## 3. 스탠다드 AC
AC는 인터페이스에 IN, OUT으로 구성이 가능하다. 
### IN으로 걸었을 경우
- 패킷이 IN하면 AC 유무를 확인하고, 
  - 있으면 AC 주소와 패킷 출발지 주소를 확인한다. 
  - 없으면 바로 경로로 
- 일치하면 AC 수행한다. 만약 불일치하다면 Deny. 일치하면 경로로 

- AC 구성: 
- > access-list access-list number {permit|deny} {source [source-wildcard]}
- interface 적용
- > ip access-group access-list-number {in|out}
- ex. AC를 이더넷 인터페이스 0에 적용하고 싶으면, ip access group 0 in 
- wildcard mask란, OSPF & AC에만 사용한다. 

## 4. extended AC
- 스탠더드와의 차이
  - 출발지와 목적지 모든 제어를 한다. 
  - 프로토콜을 지정 가능하다. 
  - ac number를 100 ~ 199까지 사용한다. 
  - > access-list access-list number {permit|deny} 
    > protocol source source-wildcard [operator port]
    > destination destination-wildcard [operator port] [established] [log]
  - established란, tcp 데이터 그램이 ack, rst bit이 set 되어 들어오는 경우. 

## 5. HSRP
라우터의 장애 대비한다. 시스코 장비에서만 사용한다. 
라우터 고장에 대비해 라우터 한대를 더 구성에 포함해 메인 라우터가 고장나면 자동으로 두번째 라우터! 
1. 디폴트 게이트웨이 문제를 해결한다. 실제 존재하지 않는 가상의 라우터 ip 주소를 디폴트 게이트웨이로 세팅하고, 그 주소에 대해 active/standby 라우터를 두고, 액티브 문제시 그 역할을 대체한다.
2. 트래밍: 시리얼 회선 문제시에도 라우터를 교체 가능하다. 

## 6. NAT
한 쪽 네트워크의 ip 주소가 다른 네트워크로 넘어갈 대, 변환돼 넘어간다. 
### NAT 사용 이유
- 내부 네트워크: 비공인 IP, 외부 인터넷: 공인 ip 사용
- 기존 isp에서 새 isp로 이동시, 내부 전체 ip를 유지
- 2개의 인트라넷을 합할 시, 네트워크 IP가 겹치는 경우
- TCP로드 분배가 필요하면 겉으로는 한개 내부에서는 여러개로 매핑한다. 
- > ip nat pool ccie 시작주소 끝주소 netmask 서브넷 주소 (내부 주소가 밖으로 나가며 바뀔 주소)
  > 
  > ip nat inside source list 1 pool ccie ( 인사이드로 정의한 인터페이스에서 들어온 출발지 주소=액세스 리스트가 1일 경우, 정의된 주소로 변환)
  > 
