어떻게 하면 만든 어플리케이션을 공유할 수 있을까? 

## Docker hub
- sign up 후 Create Repository를 한다. 

내가 만든 이미지를 올리려면, docker push를 한다. 
> docker push hackertaco/getting-started:tagname

근데 fail. 왜? Login 안 해서.
> docker login -u ${username}

login이 성공하면, 다시 해주자. 
태그를 뒤에 입력하지 않으면, 기본값은 latest다.

이렇게 이미지가 푸시되면, 새로운 인스턴스에서 이것이 실행되는지 확인하자. 

[Play with Docker.](https://labs.play-with-docker.com/)

