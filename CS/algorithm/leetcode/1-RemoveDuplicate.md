## Remove Duplicate (Array)

배열이 주어졌을 때 중복 요소를 제거하는 알고리듬. 
그 배열 자체로 중복을 제거하고 다른 추가 메모리를 사용하지 말라고 지시를 받은듯하여 그 배열 그대로 중복을 제거하는 코드를 작성했다.

for문으로 한바퀴 도는 것은 하지 않을 수 없는듯한 문제다. 다만 다른 자료구조를 만들어낼 수도 없으므로 포인터 개념으로 k를 두어서 for문을 돌수록 증가하는 i 와 비교하고, 경우에 따라 삽입하는 코드를 작성하였다.


https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727


```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int k=0;
        int i;
        if(nums.length == 1){
            return ++k;
        }
        for(i=1; i<nums.length;i++){
            if(nums[k] != nums[i]){
                if(nums[k+1] == '_'){
                    nums[k+1] = nums[i];
                    nums[i] = '_';
                }
                k++;
                
            }else{
                nums[i] = '_';
            }
        }
        return k+1;
    }
}
```
메모리 사용량과 시간 복잡도는 아래와 같다. 
![Alt text](image.png)

다른 사람들은 어떻게 풀었나 궁금하여 찾아보았다.
대부분 나와 비슷하게 푼듯했다. 그런데, 나처럼 _를 체크하지 않은 걸 보니 내가 또 문제를 잘못 파악한듯 싶다..

문제 예시에서는 끝 부분에 _ 처리를 하라는 식으로 되었는데, 굳이 그렇게 하지 않아도 되었던 것 같다. 
중요한 포인트는 포인터를 두어서 비교하고, 값이 다를 경우 삽입한다는 것이다.
```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        if(n<=1){return n;}
        
        int left = 0; //everything to the left of left(inclusive) is good
        int right = 1;//the current element we are processing
        
        while(right<=n-1){
            if(nums[right] == nums[left]){
                right++;
            }
            else{
                nums[left+1] = nums[right];
                left++;
                right++;
            }
        }
        
        return left+1;
    }
}
```