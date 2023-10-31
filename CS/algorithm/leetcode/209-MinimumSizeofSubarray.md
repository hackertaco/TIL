
## 209-
https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150

어렵지는 않지만 귀찮은 문제..
```java
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int start = 0;
        int sum = 0;
        int len = Integer.MAX_VALUE;
        for(int end = 0; end < nums.length; end++){
            sum += nums[end];
            while(sum >= target){
                len = Math.min(len, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        if(len == Integer.MAX_VALUE) return 0;
        return len;
    }
}
```