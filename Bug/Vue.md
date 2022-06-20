## Event Bubbling 금지
이벤트 버블링을 막아보고자 event.stopPropagation() 기능을 하는 .stop을 이벤트 핸들러에 넣었으나, 
도무지 작동을 하지 않음
- 해결 방법: 부모 component에서 import한 component에 @click.stop을 거는 것이 아닌,
해당 컴포넌트 <파일>에 직접 @click.stop 적용 


## 구글 포토 src가 안 먹을 때
rel 속성을 확인해본다
리퍼러 헤더를 noreferrer로 넘기지 않을 수가 있다.

## 갑자기 ERR-connection-timed-out 에러가 뜰 때
`vue.config.js` devServer 객체 내 port번호를 localHost와 일치시켜야

## Vue에 바인딩된 sync값의 경우
내부 내용을 정확히 짚어주어야 한다. deep하게 적용되지 않을 수가 있다.

## keep-alive
TCP에서 파악했다시피, V-tab의 경우 다른 컴포넌트로 변할 때 연결이 달라지게 되는데, 재렌더링을 방지하기위해 컴포넌트를 감싸는 형태로 쓰여지게된다.
keep-alive는 연결을 지속한다는 의미로, 지속 커넥션의 Keep-alive 요청과 동일하지는 않으나, 의미는 동일하다.
