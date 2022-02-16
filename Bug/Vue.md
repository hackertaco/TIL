## Event Bubbling 금지
이벤트 버블링을 막아보고자 event.stopPropagation() 기능을 하는 .stop을 이벤트 핸들러에 넣었으나, 
도무지 작동을 하지 않음
- 해결 방법: 부모 component에서 import한 component에 @click.stop을 거는 것이 아닌,
해당 컴포넌트 <파일>에 직접 @click.stop 적용 
