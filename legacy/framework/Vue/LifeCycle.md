### Virtual Dom
Dom의 복사본, js 객체.
어떤 data의 변화가 감지되었을 때, Dom과 실제로 다른 부분만 계산하여 변화시켜주기에 상당히 반응속도가 빠르다.

브라우저에 렌더링 엔진은 Virtual Dom을 가져온다.
이는 이미 Dom 처리가 되어있어서, DOM + CSS Attachment 작업부터 시작된다.

## Life Cycle
1. created 

- Virtual DOM이 실제 브라우저 Dom에 안착되기 전
- data에 접근 가능

2. mounted
- virtual dom이 실제 dom에 붙여짐
