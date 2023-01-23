## 실행 컨텍스트
코드의 실행환경에 대한 여러 정보를 담고있는 개념.
JS 엔진에 의해 만들어지고 사용되는 코드 정보 객체 집합

### 종류
- 글로벌 스코프에서 실행하는 글로벌 코드
- 함수 스코프에서 실행하는 함수 코드
- eval()로 실행되는 코드

엔진이 스크립트 파일을 실행하기 전에,
글로벌 실행 컨텍스트가 생성되고, 
함수를 호출할 때마다,
함수 실행 컨텍스트가 생성된다.

### 실행 컨텍스트 스택?
실행 컨텍스트 스택은, 흔히 콜 스택이라고 불리는 스택에 쌓인다.
Global Execution Context는 코드를 실행하기 전에 쌓여 모든 코드를 실행함ㄴ 제거된다.
Function Execution Context는 호출할 때 싸여 호출이 끝나면 제거된다. 

```javascript
function func() {
console.log('함수 실행 컨텍스트');
}
console.log('글로벌 실행 컨텍스트');
func();
```

여기서, 코드를 실행하기 전에 GEC가 쌓이고 코드를 실행하며 콘솔에 "글로벌 실행 컨텍스트" 출력
그 다음 func()을 호출, 그에 대한 FEC가 만들어진다.

### 구성요소
실행 컨텍스트는 
- Lexical Environment
- Variable Environment
- this 바인딩
의 구성요소를 갖는다.

#### Lexical Environment
- 변수 및 함수 등의 식별자에 대한 환경적 기록
- 외부 참조에 관한 정보를 가지고 있는 컴포넌트다.

Environment Record가 식별자에 대한 정보를 가지고 있고,
outer 참조는 외부 Lexical Environment를 참조하는 포인터다.

```javascript
let x = 10;
 
function foo() {
  let y = 20;
  console.log(x);
}
```
이와 같은 코드가 있을 때, 아래와 같이 Lexical Environment 형성됨.
```javascript
globalEnvironment = {
    environmentRecord = { x: 10 },
    outer: null
}
fooEnvironment = {
    environmentRecord = { y: 20 },
    outer: globalEnvironment
}
```
foo()에서 x를 참조할 때는, 현재 Environment Record를 찾아보고 없어서, outer 참조를 사용한 외부 Lexical Environment의 Environment Record를 찾아보게된다.

#### Variable Environment
Lexical Environment과 동일한 성격을 띄지만, `var`로 선언된 변수를 저장한다.

#### this 바인딩
실행 컨텍스트가 생성될 때마다, this 객체에 어떻게 바인딩이 되는지를 나타내었다.
ES6부터 this의 바인딩은 LexicalEnvironment 내의 EnvironmentRecord 안에서 일어난다.
- GEC는,
  - strict 모드일 경우 undefined, 
  - 아니면 글로벌 객체 (브라우저에서는 window, nodejs에서는 global)
- FEC는,
    - 해당 함수가 어떻게 호출되었는지에 따라 바인딩

### 과정
크게 생성단계와 실행 단계의 과정으

#### 생성단계
1. Lexical Environment
2. Variable Environment
3. this 바인딩
단계를 거친다. 값은 변수에 매핑되지 않는다. 
`var`는 undefined, `let, const`는 아무 값도 가지지 않는다.

#### 실행단계
```javascript
var a = 3;
let b = 4;

function func(num) {
  var t = 9;
  console.log(a + b + num + t);
}

var r = func(4);
```

- GEC의 생성
```
GEC {
	ThisBinding: window,
	LexicalEnvironment: {
		EnvironmentRecord: {
			b: 4,
			func: func(){...}
		},
		outer 참조: null
	},
	VariableEnvironment: {
		EnvironmentRecord: {
			a: 3,
			r: undefined
		},
		outer 참조: null
	}
}
```
- GEC의 실행
```
GEC {
	ThisBinding: window,
	LexicalEnvironment: {
		EnvironmentRecord: {
			b: 4,
			func: func(){...}
		},
		outer 참조: null
	},
	VariableEnvironment: {
		EnvironmentRecord: {
			a: 3,
			r: undefined
		},
		outer 참조: null
	}
}
```
이제 `func()` 을 호출하고 FEC를 생성한다.

- FEC의 생성 단계
```
FEC {
	ThisBinding: window,
	LexicalEnvironment: {
		EnvironmentRecord: {
			arguments: { num:4, length:1 }
		},
		outer 참조: GEC의 LexicalEnvironment
	},
	VariableEnvironment: {
		EnvironmentRecord: {
			t: undefined,
		},
		outer 참조: GEC의 LexicalEnvironment
	}
}
```

- FEC의 실행 단계

```
FEC {
	ThisBinding: window,
	LexicalEnvironment: {
		EnvironmentRecord: {
			arguments: { num:4, length:1 }
		},
		outer 참조: GEC의 LexicalEnvironment
	},
	VariableEnvironment: {
		EnvironmentRecord: {
			t: 9,
		},
		outer 참조: GEC의 LexicalEnvironment
	}
}
```

FEC가 스택에서 제거되고, GEC의 r이 20으로 초기화
```
GEC {
	ThisBinding: window,
	LexicalEnvironment: {
		EnvironmentRecord: {
			b: 4,
			func: func(){...}
		},
		outer 참조: null
	},
	VariableEnvironment: {
		EnvironmentRecord: {
			a: 3,
			r: 20
		},
		outer 참조: null
	}
}
```
