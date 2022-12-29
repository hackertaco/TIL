리눅스의 응용 프로그램들을,<br/>
프로세스 격리 기술들을 사용해,<br/>
컨테이너로 실행하고 관리하는 오픈 소스 프로젝트

- 서로 다른 머신 환경을 잘 조율해서 배포하게 돕는다.
- 운영체제를 설치할 필요없이, 하나의 운영체제 위에서 서로 다른 서비스들이 분리된 채 실행된다.

## 설치 방법
Mac OS 기준: docker.com에서 다운로드 받고, 실행
터미널에 docker images 쳤을 때 에러 뜨지 않으면 안전히 설치된 것.

## docker hub
앱 스토어와 같은 것. 
여기서 다운받는 행위를 **Pull이고**, 다운받는 걸 **image라고** 하고,
프로세스를 여기서는 **container라고** 한다.
실행하는 걸 **run이라** 한다.

## docker run ${image}
도커 이미지 실행하는 것.
docker ps를 하면 현 실행 컨테이너 볼 수 있다.

## docker 운영방식
Docker Host에는 여러 컨테이너가 만들어지고, 해당 컨테이너에 서버가 설치되었다고 가정하자.
Host의 80번 포트와 컨테이너의 포트를 연결한다.
>docker run -p 80:80 httpd
> 
> 이걸 포트 포워딩이라고 한다.

앞의 것을 호스트의 포트, 뒤의 것을 컨테이너의 포트

## docker CLI
- docker exec
- docker exec -it ${CONTAINER} /bin/sh :: 컨테이너 대상으로 하는 명령을 실시간으로 보여준다.
- 실행하고자 하는 명령어를 넣을 수 있다.

### docker image size
- OS가 차지하는 부분이 상당합니다.
- 알파인 OS(alpine OS)가 상대적으로 크기가 작다.


## docker compose
- docker run만 하게 되면, 커맨드가 상당히 길어지게 되는데, 