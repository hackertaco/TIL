**Deep Scrap**이라 명명한 스크래핑 방법론 제시하는 논문.
이는 특정 유저의 페이지에 보이는 최근 트윗을 크롤링한다.
멀티프로세싱 아키텍처를 사용하여, 트위터의 크롤링 정책을 위반하지 않으면서도, 병렬성을 최대화한다.
그 결과 기존 트위터에서 제공하는 Api에 비하여 훨씬 많은 트윗을 크롤링할 수 있었다. (약 20배 차이)

# Introduction

상당히 많이 사용하는 서비스이니만큼, 다양한 업종에서 트위터가 연구된다.
그런데 이 트위터의 글을 명명하는 트윗은 두가지 방법으로 수집 가능하다.
하나는 자체 제공 API, 다른 하나는 웹페이지를 크롤링하는 것이다.

공식 API는 허용된 방법이니만큼 공인된 사용자가 수집할 수 있다.
그러나, 수집 가능 개수나, 시간, 가격 등에서 제한이 있다.

웹페이지를 크롤링하는 방식은 그 한계를 극복할 수는 있지만, 트위터가 robots.txt를 통하여 허용하는 범위 내에서 진행하여야한다.

그간 위의 두가지 방법들에 관련한 논문들이 있었으나, 제한이 있거나, 완전하지는 않았다.
따라서 이 논문은 Deep Scrap이라는 방법론을 제시한다. 크롤링 속도를 향상시키면서도, robots.txt규약을 지키게끔 한다.

- 멀티프로세싱 아키텍처 도입. 멀티 프로세스에 서로 다른 ip를 부여하고, 이전 접근 페이지 정보를 인메모리 구조로 유지하여 같은 ip 주소 충돌을 막는다. 이는 크롤링 병렬성을 최대화하고, 결과적으로 속도를 향상하면서도 여러 유저들의 트윗을 긁어올 수 있었다.
- 완전한 성능을 자랑한다. 이 방법론은 전체트윗을 긁어올 수 있다.
- 효율을 자랑한다. 싱글 프로세스로 작업할 때보다 2.97배 높은 효율성을 제공했다.

# Deep Scrap의 전반적 아키텍쳐

Deep Scrap은 Scrapy와 TweetScrapper라는 오픈 소스를 사용한다.
Scrapy를 통해 Dom구조를 분석, 데이터를 추출하고 TweetScrapper를 통해 검색 키워드를 제공한다.
이 둘을 이용해 두가지 기능을 개발했다.

1. 병렬 크롤링

- 멀티 프로세스를 이용해 동시에 N개의 프로세싱 유닛을 크롤링한다.
  Scrapy나 TweetScraper는 해당 기능을 지원하지는 않지만, 우리는 각각의 프로세스를 크롤링 엔진에 연결시켜 멀티프로세싱을 지원했다.
  결과적으로, N개의 프로세스가 동시에 이뤄졌다.

2. 멀티 프로세스에 다른 ip부여

- 트위터에서 직접적으로 멀티 프로세싱하는 것은 가로막힌다.
  따라서 우리는 토르 네트워크를 통하여, 멀티 프로세스에 서로 다른 ip를 부여했다.
  Deep Scrap은 멀티프로세스를 서로 다른 포트 번호를 따라 작동하고 각 프로세스는 tor browser를 통하여 트위터 서버와 연결된다.

그 이후 각각의 포트넘버를 서로 다른 ip에 부여하고, 토르 네트워크 내의 마지막 노드가 트위터 서버와 연결된다.

이를 통하여 하나의 머신으로도 병렬을 유지한다.
그러나 이 과정에서 마지막 노드가 서로 부딪힐 수 있다. 이 경우 이전 페이지를 연결지어놓고 재시작하게 한다.

# Deep Scrap의 완결성

이 기술을 통하여, 222,194의 트윗을 수집할 수 있었다. 같은 유저에 대해 공식 api는 12,586개를 수집했다.
그러나 트위터에서 제공하는 지역정보 유저 정보 등은 가져올 수 없었다.

# 실험 결과

크롤링 속도는 Deepscrap은 오직 네트워크 대역폭에 영향을 받는 반면 api는 딜레이 시간이 정해져있다. 즉, 트위터는 88개의 트윗을 초당 수집 가능하다. Deepscrap이 공식 api보다 빠르지는 않으나, 지속적으로 수집가능하고 효율성에서 더 좋다.

# 관련연구

관련 연구로는 기존 api를 이용한 것, 그리고 웹페이지 크롤링을 한 것들로 나눠볼 수 있겠다.
그간 관련 연구들은 많았으나, 제한들을 극복해내지는 못하였고, 그게 아니면 수가 적어 완전하게 크롤링되었는지 확인이 어려운 연구들이었다.

# 결론

DeepScrap은 특정 유저의 페이지에서 볼 수 있는 트윗을 크롤링하는 기술이며, 이 기술의 속도를 높이기위하여 멀티프로세싱을 도입했고, 완전하게 수집할 수 있음을 보여주었다.

그러나 수집할 수 없는 정보들도 있기에, 이를 확장시켜 가져와볼 수 있게끔 할 예정이다.
