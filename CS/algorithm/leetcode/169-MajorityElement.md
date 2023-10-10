## 169. ME
배열 내에 majority element를 찾아내야한다.

나의 경우 우선 sort 하고 경계선에서 카운트를 검사했다. 



```java
class Solution {
    public int majorityElement(int[] nums) {
        int len = nums.length;
        Arrays.sort(nums);
        int curr = nums[0];
        int count = 0;
        int result = curr;
        int max = 0;
        for(int i = 0; i<len; i++){
            if(count > max){
                max = count;
                result = curr;
            }
            if(nums[i] != curr){
                curr = nums[i];
                count = 1;
            }else{
                count++;
            }
        }
        if(count > max){
            result = curr;
        }
        return result;
    }
}
```
그런데 아래와 같은 똑똑한 방법도 사용할 수 있다. candidate으로 남아있다면 그는 반드시 다수에 속한다는 인사이트를 얻을 수 있다.
```java
public int majorityElement(int[] nums) {
        int n=nums.length;
        int count = 0;
        int candidate = 0;

        for(int element : nums ){

            if(count == 0){
                candidate = element;
               
            }
            if( element == candidate){
                count++;
            }
            else{ // the current element is different from the candidate, decrement count by 1.
                count--;
            }
        }
      return candidate;
       
    }
```