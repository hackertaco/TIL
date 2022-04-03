## Http 캐시를 효율적으로 관리하려면
- Cache-Control 헤더를 섬세히 조절할 필요
- 웹 브라우저가 서버에서 지금까지 요청한 적이 없는 리소스를 가져오려고 할 때, 서버와 브라우저는 완전한 HTTP 요청과 응답을 주고받는다
- Cache-Control 헤더에 따라, 이후 리소스의 생명주기가 결정된다.

## Cache-Control

- max-age=<seconds>값을 지정하게되면, 이 리소스의 캐시가 유효한 시간은 <seconds>초가 된다.
- 유효기간이 지나면 > 재 검증 
- 캐시가 유효하다면, 서버는 [304 Modified] 요청을 내려준다. 해당 리소스의 캐시검증에는 얼마 안되는 바이트의 송수신이 일어난다.

* 재검증 요청 헤더
- If-None-Match: 캐시된 리소스의 ETag와 서버의 Etag 비교
- If-Modified-Since: 캐시된 리소스의 Last-Modified값 이후에 서버 리소스가 수정되었는지 확인
- 캐시가 유효하지 않을시, 서버는 [200 OK] 또는 적합한 상태 코드를 본문과 함께 내려준다.


### no-cache no-store
Cache Control에서 가장 헷갈린다. 
- no-cache는 캐시는 저장하나 매번 서버에 재검증 요청을 보낸다
- no-store는 캐시 자체를 저장하지 않는다.
