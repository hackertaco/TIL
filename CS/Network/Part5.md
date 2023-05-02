## 01. IP 주소 1
IP 주소? TCP/IP 프로토콜에서 장비 구분을 위한 주소다. 2진수 8자리마다 점을 찍어서 Octet이라고도 불린다. 

## 02
라우터 1개에 이더넷/시리얼 인터페이스가 있다. 

두개 주소에 배정이 필요하다.

- 이더넷 인터페이스는 내부 네트워크
- 시리얼 인터페이스는 외부 네트워크
라우터 IP/ pc IP는 달라야한다. 
- 시리얼 인터페이스 주소는 우리 맘대로 부여할 수가 없고, 라우터 접속 상대 라우터의 시리얼 인터페이스와 맞추어야한다. 

## 03
네트워크 부분과 호스트 부분을 구분한다. 

네트워크 부분은 브로드캐스트 영역, 라우터 거치지 않고 통신이 가능하다.

호스트 부분은 달라도 네트워크 부분은 같아야 정상적 통신이 가능하다.

## 04
- IP 주소를 보고 네트워크 부분과 호스트 부분을 나눌 수 있다. = ip 주소의 클래스
- A, B, C, D, E 로 나눈다. 이는 네트워크 크기에 따른 구분이다. 
  - A: 가장 많은 호스트 수를 가질 수 있다. 
    - 맨 앞자리(2진수 입장)가 항상 0으로 시작
    - 앞의 8비트가 네트워크 부분
    - 1.0.0.0 ~ 127.0.0.0
    - 2^24 - 2개의 호스트 주소가 가능
    - 호스트 주소가 x.0.0.0인 경우: 네트워크 자체를 나타내고, x.1.1.1인 경우: 브로드캐스트 주소
  - B: 맨 앞자리가 무조건 10으로 시작된다. 
    - 128 ~ 191
    - 앞 16비트가 네트워크 부분
    - 2^16 -2 개의 호스트 주소 -> 6만 5534개
  - C는 110으로 시작
    - 192 ~ 223
    - 앞 24비트가 네트워크
    - 254개의 호스트 주소
  - D는 멀티캐스트용
  - E는 연구용

## 05
기본 게이트웨이란: 내부 네트워크에서 컴퓨터 안보이면 밖으로 통하는 문, 
- 즉 라우터의 이더넷 인터페이스 아이피

## 06 subnet mask
너무 호스트 개수가 많으면 브로드 캐스트의 영향이 너무 크다. 그래서 나눠야한다. 

- 서브넷 마스크란 IP 주소를 나눌 때 쓴다.
- 주어진 IP 주소를 네트워크 환경에 맞게 나눠주기 위해 씌우는 이진수의 조합이다. 
- 각 서브넷 간 통신은 라우터를 통한다.
## 07 서브넷 마스크 기본? 
모든 아이피 주소에는 서브넷 마스크가 따라다닌다. 
- 주소를 나누지 않더라도. 그래야 해당주소가 서브넷으로 나뉘었는지 아닌지 확인이 가능하다. 
- 주소를 안 나누면 서브넷 마스크를 default subnet mask라고 하고, 
  - 클래스 A: 255.0.0.0
  - B; 255.255.0.0
  - C: 255.255.255.0
- 주소를 나누게 되면
  - ip, default subnet mask AND 연산! 

## 08 서브넷 마스크 기본 성질
서브넷이란 이 서브넷 마스크로 만들어진 네트워크다. 
- 이 서브넷 끼리는 라우터를 통한 통신만 가능하다. 
- 서브넷 마스크는 이진수일 경우 1이 연속적으로 들어가게된다. 
  - ex. 255.255.255.10은 안되지만, 255.255.255.252(11111100)은 된다.

## 09 
- 서브넷도 엄연한 하나의 네트워크
- 서브넷 마스크는 연속적으로 1이 필요