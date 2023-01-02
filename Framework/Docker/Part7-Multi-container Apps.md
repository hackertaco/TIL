지금까지, 하나의 컨테이너 앱으로만 작업했는데, 이제는 애플리케이션 스택에 MySQL도 추가하고 싶어졌다. 
그럼 MYSQL은 어디서 run 되는거지? 

일반적으로, 각각의 컨테이너는 하나만 잘 해야한다.

- 데이터베이스와는 다르게 프론트엔드와 api를 확장해야할 가능성이 높다. 
- 별도의 컨테이너를 사용하면 별도로 버전관리를 할 수 있다. 
- 로컬에서 데이터베이스 컨테이너를 돌리는 동안, 배포할 데이터베이스 서비스를 사용하고 싶어질 것이다. 
- 다양한 프로세스를 돌리는 것은 프로세스 매니저를 요구할 것이고, 복잡도를 높인다. 

## 컨테이너 네트워킹
컨테이너는 기본적으로 독립적으로 돌아가고, 같은 머신 내의 다른 컨테이너나 프로세스는 잘 모른다. 

그래서, 어떻게 우리는 하나의 컨테이너가 다른 컨테이너와 통신할 수 있게 할 것인가? 
답은 = 네트워킹이다. 

## 일단 MySQL 시작하기

컨테이너를 네트워크에 넣는 두가지 방법 
1) 시작할 때 도입
2) 있는 컨테이너에 연결

우선 네트워크를 생성하고, MySQL 컨테이너를 시작할 때 붙여볼 예정이다.

> docker network create todo-app
> 
> docker run -d \
--network todo-app --network-alias mysql \
-v todo-mysql-data:/var/lib/mysql \
-e MYSQL_ROOT_PASSWORD=secret \
-e MYSQL_DATABASE=todos \
mysql:8.0

- mysql run 하는 코드

>docker run -it --network todo-app nicolaka/netshoot

네트워킹 이슈 문제를 해결하고 디버깅하는 데 많은 기능을 제공하는 컨테이너를 사용한다. 



--network-alias 플래그는 무엇인가? 호스트네임이 아닐지라도, 해당 플래그 이름을 통해서 ip 주소를 얻어낼 수 있다.

이게 무슨 말이냐면, 그저 mySQL이라는 이름으로 호스트와 연결된다. 



> docker run -dp 3000:3000 \
-w /app -v "$(pwd):/app" \
--network todo-app \
-e MYSQL_HOST=mysql \
-e MYSQL_USER=root \
-e MYSQL_PASSWORD=secret \
-e MYSQL_DB=todos \
node:18-alpine \
sh -c "yarn install && yarn run dev"
> 

켄테이너를 웹 네트워크에 연결. 

그런데, 이 경우 네트워크를 만들고 -> 컨테이너를 시작하고 -> 모든 환경 변수를 지정 -> 포트를 노출 해야하는,
기억할 게 많고 전달도 어렵다.
