## 01
라우터란 지능을 가진 경로 배정기이며, 세팅을 우리가 해야한다. 

## 02 라우터의 일
1. 경로 결정: 데이터 패킷이 목적지까지 갈 수 있는 길을 검사, 적절한지 결정
2. 스위칭: 경로가 결정되면 데이터 패킷을 스위칭

어떻게 어디가 빠르고 안전한지 계산? 
- 라우팅 프로토콜( 알고리즘 )
- 사용하는 것 = 라우팅 테이블

## 03. 라우터의 생김새

## 04. 라우팅 프로토콜과 라우티드 프로토콜
- 라우팅 프로토콜: 라우팅해주는 프로토콜 
  - RIP, IGRP, OSPF, EIGRP
  - routing 테이블 이용
    - 목적지와 목적지까지 거리, 어떻게 가야하는지 적힌 테이블
- 라우티드 프로토콜: 라우팅을 당하는 프로토콜
  - tcp/ip, IPX, AppleTalk

## 05 
- 스태틱 라우팅 프로토콜: 사람이 일일이 경로 입력 프로토콜
  - 라우팅 속도 오르고 메모리는 덜 쓴지만 귀찮다. 작은 규모에서 사용
- 다이내믹 라우팅 프로토콜: 그 때 그때 기계가 좋은 방식 
  - 라우터에 부담이 된다. 
  - RIP, IGRP, OSPF, EIGRP

## 06. routing table
라우터의 네트워크 지도를 말한다. 전원이 꺼지면 모두 지워진다. 
> show ip route 

## 07.
- AS: Autonomous System: 하나의 네트워크 관리자에 의해 관리되는 라우터 집단
  - 정보의 효율적 관리가 가능하고 간편하게 인터넷 서비스를 한다. 
  - AS 밖으로 나갈 땐, AS에 있는 문지기 라우터에 묻고 나간다. 이 문지기는 인접한 다른 AS의 정보를 가지고 있다. (ASBR)
  - AS 내부용은 내부용 프로토콜. 
    - RIP, IGRP, OSPF, EIGRP
  - 외부용은 EGP, BGP

## 10 라우터 내부
1) RAM: 라우터 운용 시스템
2) 라우터도 운영체제를 갖고있다. IOS 사용
3) NVRAM: 비휘발 램 구성 파일 저장
4) 플래시 메모리: 용량이 NVRAM보다 크고 운영체제를 저장 (IOS 이미지 저장)
5) ROM: 라우터의 기본 내용 기재. 기본적 IOS 탑재

## 14 스태틱 라우팅
stub으로 많이 사용한다. 스텁이란 갈 수 잇는 경로가 하나뿐인 것이다. 

> ip route network(목적지 네트워크 주소) [mask] {address|interface}

- mask: 목적지 네트워크의 서브넷 마스크
- address: 1hop 건너 뛴 주소
- interface: 목적지로 가려면 어떤 interface 사용할지?

## 15 디폴트 라우팅: 경로를 찾지 못한 모든 네트워크가 가는 길
1) 인터넷을 사용하는 라우터
2) 스텁 네트워크에 있는 라우터

둘 모두가 디폴트로 정한 곳으로 간다. 