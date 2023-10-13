## github에 이미 올라간 파일 삭제하기
```java
// 깃에서 추적 중인 모든 파일 삭제 (스테이징 영역에서만 삭제됨, 로컬 파일은 전부 남아있으니 걱정 안 하셔도 됨)
$ git rm -r --cached .

// 모든 파일 add해서 스테이징에 올림 
$ git add .

// 추적을 끝내기를 원하는 파일(ignore 처리된 파일)이 delete 된 내용으로 커밋을 생성
$ git commit -m "apply .gitignore"

// 원격 서버에 푸쉬
$ git push
```