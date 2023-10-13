## 45. -Jump Game 2
https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150
어떤 지점으로 가는 가장 짧은 수를 구하는 문제.
BFS로 해결한다.
```java
class Solution {
    public int jump(int[] nums) {
        int result = 0;
        int far = 0;
        int end = 0;
        if(nums.length ==1)return result;
        for(int i = 0; i <= nums.length-1; i++){
            far = Math.max(far, i+ nums[i]);
            if(far >= nums.length -1){
                result++;
                break;
            }
            if(i == end){
                result++;
                end = far;
            }
        }
        return result;
    }
}
```