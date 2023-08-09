일종의 테크닉이다. 

특별한 속성을 가진 복잡한 문제를 푸는 방법이다. 
복잡한 문제를 그보다 단순한 하위문제로 나누어서 풀게된다. 
- 재귀적! 
- 가장 단순한 문제 +1은 그 다음으로 단순한 문제다. 이걸 반복하면 원래의 복잡한 문제까지 해결한다. 

### 배낭 문제
- 크기와 가격이 다른 여러 물품이 있는데
- 값아치가 최대가 되도록 구성해야하는데,
- 주먹구구식으로 풀 경우 모든 경우의 수를 따져봐야한다. 
- 물품 하나가 추가될 때마다 경우의 수가 두배씩 뛴다. O(2^n)

재귀함수에서, 중복을 제거한다. 기록을 해서!
그것이 메모이제이션

## memoization
- 계산 결과를 캐시에 저장해둔 뒤, 나중에 재사용하는 기법
- 보통 함수가 매개변수에 따라 반환하는 값을 캐싱하는 것을 지칭한다. 

```java
public static int fibonacciRecursive(int number, int[] cache) {
    if(number <=1){
        return number;
    }

    if(cache[number]!=0){
        return cache[number];
    }

    int ret = fibonacciRecursive(number - 2, cache) +fibonacciRecursive(number - 1, cache)

    cache[number] = ret;
    return ret;
}
```

이 메모이제이션을 동적 계획법에서 사용하기도 한다. 다른 곳에서도 메모이제이션을 사용한다. 

### top-down 동적 계획법
- 최종적으로 풀려하는 복잡한 문제에서 시작
- 필요에 따라 재귀적으로 하위 문제를 푼다. 두번 이상 평가하는 문제는 캐시 덕분에 계산을 생략한다. 
- 기존의 재귀 함수를 크게 변경하지 않아도 된다는 장점이 있다. 그냥 캐시 로직을 추가할 뿐이다. 


