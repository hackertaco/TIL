## 42. -Trapping Water
https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150
물을 가둬놔야한다. 더 작은 쪽에서 계산하는 것이 맞기때문에 양쪽 포인터를 두고 작은 것중에 제일 큰 값에서 작은 값을 빼준 걸 더한다.
```java
class Solution {
    public int trap(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int lMax = Integer.MIN_VALUE;
        int rMax = Integer.MIN_VALUE;
        int result = 0;
        while(left <= right){
            lMax = Math.max(lMax, height[left]);
            rMax = Math.max(rMax, height[right]);

            if(lMax < rMax){
                result += lMax - height[left++];
            }else{
                result += rMax - height[right--];
            }
        }

        return result;
    }
}
```