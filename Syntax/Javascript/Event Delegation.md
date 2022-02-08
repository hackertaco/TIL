# 이벤트 버블링
- 하위 엘리먼트에 이벤트 발생시, 상위요소까지 이벤트가 전달되는 방식

# 이벤트 캡쳐링
- 하위 엘리먼트에 이벤트 핸들러가 있을 때, 상위 엘리먼트부터 이벤트가 발생하기 시작해서 하위 엘리먼트까지 이벤트가 전달되는 방식
```html
<div>
  <ul>
    <li>예시</li>
  </ul>
</div>
```
```javascript
document.querySelector('li').addEventListener('click', () => console.log('li 클릭'));
document.querySelector('ul').addEventListener('click', () => console.log('ul 클릭'));
document.querySelector('div').addEventListener('click', () => console.log('div 클릭'));
```
정상적으로는 아래와 같이 이벤트 버블링으로 진행.
```html
li 클릭
ul 클릭
div 클릭
```
만약 이를 이벤트 캡쳐링으로 바꾸기위해서는 addEventListener의 마지막 인자로 {capture:true} 전달하기.
```javascript
document.querySelector('ul').addEventListener('click', () => console.log('ul 클릭'), { capture: true });
```
```html
ul 클릭
li 클릭
div 클릭
```

Li 부터는 다시 이벤트 버블링 작동.

# 이벤트 위임
- 하위 엘리먼트들이 여러개 있을 때, 하위 엘리먼트들에 각각 이벤트 핸들러를 다는 게 아니고, 상위 엘리먼트에서 그들을 제어.
- 이렇게 하면 
- 동적으로 엘리먼트를 추가할 때마다 핸들러를 고려할 필요가 없다.
- 상위 엘리먼트에 하나의 이벤트 핸들러만 추가하면 돼서, 코드가 깔끔해진다
- 메모리에 있게되는 이벤트 핸들러가 적어져, 퍼포먼스 측면에서 이점이 있다.
```javascript
<ul onclick="alert(event.type + '!')">
    <li>첫번째</li>
    <li>두번째</li>
    <li>세번째</li>
</ul>
```
