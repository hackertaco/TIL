## HOF? 
좀 더 유연하고 반복이 없는 코드를 만들기 위해서는 어떻게 해야할까. 
HOF가 그 힌트를 줄 수도 있다. 
이를테면, 1부터 7까지 차례대로 들어있는 배열에서, 4보다 큰 수를 배열에서 필터링 할 때, 
```javascript
for(let i = 0; i<numbers.length; i++){
    if(numbers[i] > 4){
        filtered.push(numbers[i])
    }
}
```
처럼 표현해볼 수도 있지만, 
```javascript
const numbers = [1, 2, 3, 4, 5, 6, 7];
const isGreaterThan = x => x > 4;
numbers.filter(isGreaterThan); // [5, 6, 7]

```
이렇게 표현하는 것이 훨씬 깔끔하다.
이렇게 할 수 있는 것은 함수가 함수를 인자로 받거나, 함수가 함수를 반환할 수 있기 때문이다. 
이는 HOF의 큰 특징이다. 
HOF는 함수의 합성을 가능케한다.

이는 함수형 프로그래밍을 가능하게 한다.
