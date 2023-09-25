## 1. Missing Number
숫자 없는 것을 찾는 문제다. 
```java
class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        for(int i =0; i<nums.length;i++){
            if(i != nums[i]){
                return nums[i] - 1;
            }
        }
        return nums.length;
    }
}
```
아래와 같이 하는 것이 시간 복잡도가 덜 나온다. boolean 배열을 만들어낸다.
```java
class Solution {
    public int missingNumber(int[] nums) {
        boolean[] isPresent = new boolean[nums.length+1];
        
        for(int i =0; i<nums.length; i++){
            isPresent[nums[i]] = true; 
        }
        for(int j = 0; j<isPresent.length; j++){
            if(!isPresent[j]){
                return j;
            }
        }
        return nums.length;
    }
}
```
