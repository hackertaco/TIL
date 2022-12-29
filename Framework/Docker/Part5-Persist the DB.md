## Container의 파일 시스템
컨테이너가 다양한 레이어를 사용하기에, 그 자체의 스크래치 공간이 있다. 
다른 컨테이너에서는 그 변화가 보이지 않는다. 

각자의 이미지 정의가 있다. 변화들은 컨테이너가 사라지면 사라진다. 하지만, **volumes를** 사용하면, 바꿀 수 잇다.

volumes는 호스트 머신에서 돌아와 특정한 파일시스템 경로에 연결할 수 있는 능력이 있다. 

컨테이너의 디렉토리가 마운트되면, 해당 디렉토리의 변화는 호스트 머신에서도 볼 수 있다. 
따라서, 디렉토리가 다시 시작되면, 똑같은 파일을 보게될 것이다. 

volumes는 두 가지 타입이 있다. 우선은 named volumes만 확인해보자

이는 간단하게 데이터 버켓이다. 
물리적인 장소를 디스크에 저장하고, 해당 볼륨이름만 기억하면 도커는 이를 유지한다.

volume을 사용할 때마다, 도커는 정확한 데이터가 제공되는지 확신할 것이다. 

>docker volume create todo-db
> 
> docker run -dp 3000:3000 -v todo-db:/etc/todos getting-started

이렇게 하면, todo-db라는 볼륨을 만들어서 그 볼륨에 연결하게 된다! 

volume에 대한 정보를 알고 싶다면, docker volume inspect를 해보자

`{
"CreatedAt": "2022-12-29T08:42:35Z",
"Driver": "local",
"Labels": {},
"Mountpoint": "/var/lib/docker/volumes/todo-db/_data",
"Name": "todo-db",
"Options": {},
"Scope": "local"
}`

여기서 Mountpoint는 디스크에서 실제 위치다. 대부분의 머신에서는 호스트에서 루트 액세스가 있어야는데, 저기가 바로 그곳이다.