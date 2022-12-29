## 만약, 소스 코드를 업데이트 하게된다면?
이미 컨테이너를 올리고 빌드도 한 상태에서, 코드를 바꾸게 되었다. 

코드를 바꾸고, 다시 빌드하려 한다면? 
> docker build -t getting-started .

이건 된다. 하지만
> docker run -dp 3000:3000 getting-started

이건 안된다!
이는 아직 오래된 컨테이너가 돌고 있기 때문이다. 그들은 아직 3000포트를 점령하고 있다. 
이를 고치려면, 오래된 컨테이너를 갖다 버려야한다.

## 오래된 컨테이너 갖다 버리기

우선, `docker ps` 명령어로 컨테이너의 ID를 가져온다.

그리고, docker stop으로 컨테이너를 멈춘다.
> docker stop ${container Id}

docker rm으로, 스탑한 컨테이너를 없애준다.
> docker rm ${container Id}

만약 스탑과 rm을 한번에 하고 싶다면?

`docker rm -f ${container Id}`

다시 localhost:3000에 가서, 리로드를 하면 원하는대로 바뀌어있을 것이다.

