named volumes를 이용하면, 굳이 어디에 마운트되는지에 대하여 신경쓸 필요가 없다. 

그런데, bind mounts는 정확하게 어디서 마운트 되는지 통제할 수 있다.
이는 물론 데이터 유지에도 사용되지만, 컨테이너 내에 추가적인 데이터를 제공하기도 한다. 

컨테이너가 코드 변화를 파악하고 응답하며 변화를 바로바로 보여주게끔 할 수 있는 것이다. 

### 개발 모드 컨테이너 시작하기

```typescript


docker run -dp 3000:3000 \
-w /app -v "$(pwd):/app" \
node:18-alpine \
sh -c "yarn install && yarn run dev"

```

-w /app :: 명령어가 실행될 디렉토리

-v "$(pwd):/app" :: 현재 디렉토리를 컨테이너의 /app 디렉토리에 연결한다.

node:18-alpine :: 사용할 이미지 

sh -c "yarn install && yarn run dev" :: alpine은 bash가 없기에, sh로 쉘을 표현한다. 그리고 모든 의존성을 설치하고 개발 모드로 돌린다. 

> docker logs -f ${id}

로 로그를 볼 수 있다. 나올 때는 컨트롤 씨

이렇게 하고 다시 localhost:3000에 들어가서 리로드를 하면, 
코드를 바꾸었을 때 적용된 모습을 볼 수 있다. 

데브 머신이 모든 빌드 툴이나 환경을 설치할 수 없을 때, 이렇게 하면 좋다. 
