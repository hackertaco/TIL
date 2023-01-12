## Docker에서 mysql 접속
> docker run -dp ~~~~
> 
> docker exec -it bash
> 
> mysql -u root -p

## DATABASE 생성
> CREATE DATABASE nation;

## USER 생성
> CREATE USER ${user명}@${ip주소. 실습할 땐 localhost로 한다. 원격 접속시 전체 ip를 말하는 %는 grant 옵션이 차단된다. } IDENTIFIED BY ${비밀번호}

### 권한 주기
> GRANT ${기능} PRIVILEGES ON ${database명}.${컬럼명} to ${user명}@${ip주소};
> 
> FLUSH PRIVILEGES;

## USER 삭제
> DROP USER ${user명}@${ip주소};

