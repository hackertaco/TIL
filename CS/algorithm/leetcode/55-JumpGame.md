## 55. -can jump
https://leetcode.com/problems/jump-game/
문제를 잘 정의하는 것이 중요하다.
0번째 인덱스에서 해당 인덱스가 가리키는 값까지만 인덱스 점프할 수 있을 때, 인덱스 끝까지 갈 수 있는지를 묻는 문제다. 

나는 처음에는 너무 어렵게 풀어서 런타임에러가 나왓다. 
```java
class Solution {
    public boolean canJump(int[] nums) {
        boolean result = false;
        
        if(nums.length == 1 || nums.length == 0){
            return true;
        }
        if(nums[0]!=0){
            for(int i = 1; i<=Math.min(nums[0], nums.length-1); i++){
                result = canJump(Arrays.copyOfRange(nums, i, nums.length));
                System.out.println(result);
                if(result == true){
                    return result;
                }
            }
        }else{
            return false;
        }
        return result;
    }
}
 ```
해당 코드는 Time Limit Exceeded 되었다.

아래 코드는 통과했다.
```java
public boolean canJump(int[] nums) {
        int reach = 0; 
        for(int i = 0; i < nums.length; i++){
            if(reach < i) return false;
            reach = Math.max(reach, i + nums[i]);
        }
        return true;
    }
    
    ```