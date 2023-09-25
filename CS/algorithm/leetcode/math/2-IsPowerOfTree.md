## 2. Is Power Of Three
3의 제곱수인지 아닌지 찾는 방법이다. 반복문도 재귀도 모두 가능하지만 아래 방법이 O(1)이다.
https://leetcode.com/explore/featured/card/top-interview-questions-easy/102/math/745/
```java
class Solution {
    public boolean isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        double three = Math.log10(n)/Math.log10(3);
        if(three % 1 == 0){
            return true;
        }
        return false;
    }
}
```