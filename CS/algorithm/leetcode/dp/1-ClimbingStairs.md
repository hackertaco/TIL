## 1. Climbing Stairs

https://leetcode.com/explore/item/569

이전의 결과를 저장해서, 그걸 가지고 연산을 진행한다.
```java
class Solution {
        int[] cache = new int[46];
    public int climbStairs(int n) {
        if(cache[n]>0){
            return cache[n];
        }
        if(n == 1)
        {
            cache[1] = 1;
            return 1;
        }
        if(n == 2){
            cache[2]=2;
            return 2;
        }
        cache[n] = climbStairs(n-1) + climbStairs(n-2);
        return climbStairs(n-1) + climbStairs(n-2);
    }
}
```