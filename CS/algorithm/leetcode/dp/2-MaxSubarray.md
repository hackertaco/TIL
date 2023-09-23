## 2. Max SubArray
https://leetcode.com/explore/item/566

가장 큰 subarray 구하는 법. 간단한 문제인거같은데 너무 어려웠다. 세세하게 처리하지않게끔 명확한 방법이 필요하다.

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int max = Integer.MIN_VALUE;
        int sum = 0;
        
        for(int i = 0; i<nums.length; i++){
            if(sum < 0)
            {
                sum = nums[i];
            }
            else
            {
                sum += nums[i];
            }
            if(max < sum)
                max = sum;
        }
        return max;
    }
}
```
아래와 같이 DP로 풀어볼 수도 있다.
```java
class Solution {
    public int maxSubArray(int[] nums) {
        // Initialize currMaxSum & take first element of array from which we start to do sum...
        int maxSum = nums[0];
        // Initialize the current sum of our subarray as nums[0]...
        int currSum = nums[0];
        // Traverse all the element through the loop...
        for (int i = 1; i < nums.length; i++) {
            // Do sum of elements contigous with curr sum...
            // Compare it with array element to get maximum result...
            currSum = Math.max(currSum + nums[i], nums[i]);
            // Compare current sum and max sum.
            maxSum = Math.max(maxSum, currSum);
        }
        return maxSum;      // return the contiguous subarray which has the largest sum...
    }
}
```