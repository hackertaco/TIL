## 보안 검색
이미지 빌드 후, docker scan으로 보안 취약점을 스캔해야한다. 

> docker scan -login
> 
> docker scan <image-name>


## 이미지 레이어링
- 이미지를 구성하는 요소를 볼 수 있다.

> docker image history getting-started

## build 캐시
.dockerignore를 통해서, 캐시 생성 가능.

## 다단계 빌드
- 런타임 종속성과 빌드 시간 종속성 분리
- 앱 실행 필요 항목만 가져와 전체 이미지 크기를 줄인다. 
