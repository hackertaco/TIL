## 69. sqrt(x)
제곱근 구하기. 결국 이진탐색으로 가능
```java
class Solution {
    public int mySqrt(int x) {
        int start = 1;
        int end = x;
        int mid = -1;
        if(x == 0 || x == 1) return x;
        while(start <= end){
            mid = start + (end - start) / 2;
            if((long) mid * mid > (long)x){
                end = mid -1;
            }else if(mid * mid == x){
                return mid;
            }else{
                start = mid+1;
            }
        }
        return Math.round(end);
    }
}
```