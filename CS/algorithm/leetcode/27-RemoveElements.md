## 27. Remove Elements
https://leetcode.com/problems/remove-element/description/?source=submission-noac
어렵지는 않았지만, 내가 포인터를 잘못 주어 오류가 자꾸 났다. 
val과 같은 수를 뒤로 보내는 연산
```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int slow = 0; 
        int fast = 0;
        if(nums.length == 1){
            if(nums[0] == val){
                return 0;
            }else {
                return 1;
            }
        }
        
        while(fast < nums.length){
            if(nums[slow] == val){
                if(nums[fast] == val){
                    fast++;
                }else{
                    nums[slow++] = nums[fast];
                    nums[fast++] = val;
                }
            }else {
                fast++;
                slow++;
            }
        }
        System.out.println(slow);
        return slow;
    }
}

```
아래와 같이 작업을 해도 된다.
```java

class Solution {
    public int removeElement(int[] nums, int val) {
        int index=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=val){
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
}
```