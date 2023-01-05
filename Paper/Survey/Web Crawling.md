## Deep Web Crawling
크롤러를 평가할 기준을 만들어준다. 

### Abstract
현존하는 deep web 크롤링 관련 기술의 주요 기능을 분석한다. 
주요 결론은 크롤러에 대한 성과 평가 기준이나 벤치마크가 부족하거나, 공공으로 사용 가능한 데이터셋의 부족으로 성능 평가가 미성숙한 분야라는 것이다.
또한, 향후 연구는 진화하는 웹 기술을 다룰 크롤러를 고안하고, 실세계를 다룰 효과적인 크롤러를 만들기위해 크롤링 효율과 스케일링을 향상하는 것에 초점을 맞춰야한다. 

### Introduction
이 서베이에서의 deep web이란, 2001년의 Bergman이 제안한 것으로, 검색 폼을 사용해서 제출된 특정 쿼리에 반응하여 동적으로 생산되는 페이지 모음이다.
웹 크롤러란 자동으로 웹페이지를 navigate 하여 정보를 회수하는 소프트웨어다. 점차 방대한 양의 deep Web의 정보도 가져오도록 개발되고있다. 

1. Automated deep Web entry points discovery.
2. Form modelling.
3. Query selection.
4. Form submission.
5. Crawling paths learning.

과정을 통하여 전형적인 웹 크롤링이 진행된다. 
이 article을 통해, 현존하는 웹 크롤링 연관 기술을 분석하고, 전반적인 청사진을 그려본다. 

4분야로 나누어서 기술을 분석한다.
1. deep web 엔트리포인트를 자동으로 찾아내는 기술
2. 자동으로 폼을 채울 수 있는 기술
3. 자동으로 크롤링 경로를 배우는 기술
4. 크롤링 퍼포먼스 평가에 사용될 수단과 데이터셋


기존에 크롤러의 효과성에 대한 평가 수단이 없고, 벤치마크가 없고, 공식적으로 사용 가능한 데이터셋이 없어서, 각기 다른 author의 연구결과를 비교 불가했다. 또한, 중요한 결론을 내리기 어려웠다.

### Related Work
Olston and Najork은 1993-2010년까지의 proposals을 다루며 deep web, surface web 크롤러를 분석했다. 
그들의 주 결론은 이미 크롤링은 많이 연구되었지만, 여전히 해결되어야할 것들이 있다고 했다.
- AJAX와 같은 동적 스크립트 대응
- 최적의 파라미터 정리 
- 웹 폼 fill
- 등..

이는 deep web 크롤링에만 초점을 맞춘 것이 아니라서, 3, 4와 같은 것들은 포함되지 않았다.

Dragut과 몇몇은 deep Web query interface에 대한 서비이를 제안했다. 2001 to 2011까지의 프로포절을 다뤘다. 
그러나, 3, 4는 제안하지 않았다.

Manvi와 몇몇은 크롤러가 데이터베이스에 의존한다는 것이었다. 그래서, 크롤링은 이 데이터베이스 내용에 성능이 달려있고, 이 영역에서 아직 풀지 못한 문제가 있다고 했다. 
그러나 많은 프로포절을 다룬거도 아니고, 4번이 부족하다.

### Discovery of deep Web sites
#### proposal 분석
deep Web 크롤링은 검색 폼을 채우는 것을 수반한다. 따라서, 사이트들의 entry point가 어디인지를 발견해야한다. 즉, deep Web의 입장 포인트인 폼을 포함하는 웹사이트 페이지가 어딘지를 예비로 알아야한다. 
여기서 검색하는 것만 deep web에서 말하는 엔트리 포인트디앋.
자동으로 이 폼을 찾는 경험적 방법을 사용하기도 하고, 훈련시키기도 한다. 감독하는 접근도 제안한다. 구분자를 이용하여 찾는 방법도 있다. 

#### 프레임워크 비교
**기능 분석**
– PT: Type of proposal, either based on heuristics or on machine learning classification
techniques.
– AP: Approach that is used to discern deep Web entry points from other types of forms,
either pre-query (in which the form is classified prior to its submission), or post-query
(in which the form is submitted and the response pages are a source of features for the
form classification).
– CF: Features of each form that are analysed to determine if the form is a deep Web
entry point.
– FO: Whether the proposal is focused towards deep Web sites of a particular domain or
not.
– AL: Classification algorithm used.
– SU: Whether the technique is supervised or not
초기에는 경험적으로, 최근에는 감독할 수 잇는 구분자에 기반한다.
대부분은 pre-query 접근을 이용한다.

최근에는 특정 도메인의 웹사이트를 찾는 데 집중되어있다. 

### Form Filling
검색 폼이 인간-컴퓨터의 상호작용을 위해 디자인 되었기 때문에, deep web 액세스는 자동화된 프로세스와 함께 그러한 인터랙션을 시뮬레이팅하기를 요구한다. 
검색 폼과 상호작용하는 agent는 두가지 임무를 수행한다.. 하나는 폼 모델링, 다른 하나는 쿼리 선택이다.

폼 모델링은 각 영역이나 관계와 연관된 시맨틱을 분별할 수 있는 서치 폼과 연관되어있다. 
쿼리 선택은 각 필드에서 적절한 타입과 도메인 값의 조합을 만들어내는 것과 연관되어있다. 

이 둘은 최대한 관련있는 결과를 많이 가져오기위하여, 그러한 값을 제출하는 것이 목표다. 둘 다 자동화 혹은 반 자동화가 가능하다.

#### 폼 모델링 
form fill을 자동화하기위한 첫 단계는, 인간 중심적으로 디자인되어있는 서치 폼을 컴퓨터가 자동으로 처리하게끔 만드는 것이다. 
이는 사소한 것은 아니다. 모든 서치 폼이 특정 웹사이트에 특별히 만들어지고, 기준이 없기 때문이다.

그러나, 디자이너들이 공통으로 따르는 패턴들이 있다. 
양식은 간단하거나, 조금 더 발전된 형태일 수 있다. 

몇몇 논문들은 이 폼을 이해하는 문제를 다루기도 했다. 어떤 것들은 머신이 작업 가능한 방식으로 각 폼을 표현하기위한 모델을 만들었다. 
대표적인 것은 flat한 폼 필드와 라벨이다. 
가장 복잡한 모델은 폼 필드와 그 라벨간의 관계 뿐 아니라, 각 폼의 발전된 기능까지를 고려한다. 
예를 들자면 시맨틱하거나 논리적으로 연관된 필드 그룹의 존재, 필수 영역, 필드의 도메인 등이다. 
Diadem은 이 맥락에서 가장 최신의 접근이다. 
그는 폼 영역을 표현하는 계층 모델을 만들고 그들끼리의 연관성을 고려한다. 

#### 쿼리 셀렉션
폼이 모델링될 때, 폼 필드의 적절한 값들의 조합을 선택할 수 있다. 그렇게 제출하면, 웹 서버가 쿼리를 조합하여 응답을 한다. 
쿼리는 정보를 얻어오는 데 꼭 필요하다. 그러나, 모든 제출은 자원 소비를 늘리고, 확장성을 방해한다. 게다가, 몇몇 쿼리는 응답 내용이 없거나 이전 쿼리에 대한 응답을 주어 쓸모가 없다.
너무 많은 쿼리를 날리면 성능에도 문제가 생긴다. 따라서 적절한 쿼리 개수를 결정하는 것이 목표다.

- 최소한의 제출을 하는 모델을 제안하기도
- 정보 추출 기술은 유저개입 없이 자동으로 키워드를 회수하기위하여 사용된다. 
- 폼 제출 후, 가장 자주 등장하는 키워드를 회수하는 방법이 제안됐다.
- 유저가 제공한 키워드로 폼을 제출하고, 응답 페이지에서 더 많은 키워드를 추출하여 더 많은 정보를 얻을 키워드를 고르는 방법도 있다. 
- 각 키워드의 정보성을 계산하는 것도 있고
- 사이트에서 랜덤 페이지로부터 키워드 풀을 처음에 가져오는 것도 있다. 적은 가중치로 나눈 빈도가 키워드들은 작을수록 선택된다.
- 구글 쿼리 로그와 프리베이스로부터 가져온 키워드를 사용하는 기술도 있다.

좀 더 발전된 폼에 대하여는 서치 폼을 쿼리 절로 바꾸는 기술을 제안하기도 했다.
즉, 쿼리가 심플한 자연어 문장으로 표현된다.
이는 오프라인으로 만들어지고, 효율을 높이기위해, 오프라인 쿼리를 실행한다. 결과 페이지는 캐싱된다. 
온라인에서 크롤링을 하며, 많은 키워드를 받고, 가장 비슷한 쿼리 절이 선택되어 결과 페이지를 리턴한다. 
