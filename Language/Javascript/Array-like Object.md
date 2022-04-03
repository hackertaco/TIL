1. array와 array-like object는 다르다.

2. arguments
모든 함수의 본문에서 사용할 수 있는 <특수 변수>
이는 배열처럼 출력된다. 심지어 Length 속성도 있다.
만약 arguments.constructor를 검사하면, Object가 뜨게 된다. 

3. 이것을 배열로 재탄생 시키기
Array.prototype.slice.call(arguments)로 하면 된다!

4. 이를 각각 나눠보자면,
Array(기본 Object 이름).prototype(배열 인스턴스 메소드에 대한 네임스페이스).slice(배열 섹션 추출, 반환).call(한 객체에서 함수를 호출 후 다른 객체의 컨텍스트에서 사용)
