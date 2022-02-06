```typescript
function helloString(message:string): string{
    return message;
}
function helloNum(message:number):number{
    return message
}
```

어떤 함수가 인자와 리턴 타입이 계속 일정할 때, 
더 많은 반복된 함수들이 생길 것이다. (너무길다는 뜻 )
any와는 다르게, 모든 걸 받아서 모든 걸 주는것과는 다르게
T를 이용하면 type으로 된 연산이 함수로 가능하게 된다. 

```typescript
function hello(message:any): any{
    return message;
}
// 
```

```typescript
function helloGeneric<T>(message: T): T {
    return message
}
```

---

사용법은, 함수를 호출할 때 직접 제네릭 타입을 지정하는 방식이 있다.
혹은, 따로 지정하지 않고 그냥 추론 규정을 따르는 경우가 있다. 
```typescript
function helloBasic<T>(message: T): T{
    return message;
}

helloBasic<string>("Mark")
helloBasic(36)

```