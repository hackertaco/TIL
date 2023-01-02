다중 컨테이너 애플리케이션을 정의하고 공유하는 데 도움이 되도록 개발된 도구 : Docker Compose

YAML 파일 생성, 서비스를 정의하고 단일 명령으로 모든 것을 돌리거나 해체 가능.

## 장점
- 애플리케이션 스택을 파일로 정의. 
- 프로젝트의 저장소의 루트에 보관하고, 
- 다른 사람의 프로젝트에 기여를 할 수 있다. 

## 설치

도커 데스크탑을 설치했다면, 이미 docker compose도 있다. 
루트에서 `docker-compose.yml`을 만든다
> docker compose version

## 실행
`docker-compose.yml`를 만들었다면, 
>docker compose up -d

## 삭제
> docker compose down
 작성 파일의 이름이 지정된 볼륨은 제거되지 않으므로, --volumes 플래그 추가 필요