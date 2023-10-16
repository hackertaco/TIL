## 238. Product Of Array Except Self
https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150
전체 곱을 for문으로 우선 돌린 뒤, 0일 때와 아닐 때를 구분해서 self값을 나눠주면 되는 간단한 문제. 
시간 복잡도가 1ms로 괜찮게 나왔다.

그런데 조금 더 간단한 느낌으로 가독성 좋게 코드를 짤 수는 없을까 ㅠㅠ
```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int total = 1;
        int zeroIdx = 100001;
        for(int i = 0; i<nums.length; i++){
            if(nums[i] == 0){
                if(zeroIdx < 100001){
                    return new int[nums.length];
                }
                zeroIdx = i;
                continue;
            }
            total *= nums[i];
        }

        for(int i = 0; i<nums.length;i++){
            if(zeroIdx < 100001){
                if(i == zeroIdx){
                    nums[i] = total;
                }else{
                    nums[i] = 0;
                }
            }else{
                nums[i] = total / nums[i];
            }
        }
        return nums;
    }
}
```