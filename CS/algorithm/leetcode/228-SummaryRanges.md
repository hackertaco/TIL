## 228. Summary Ranges
https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150

범위 맞추어 배열을 잘 자르면 되는 문제(?) 어렵지는 않은데 코드를 이쁘게 치고 싶었다.
```java
class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> output = new ArrayList<>();
        int startIdx = 0;
        int curr = 0;
        int endIdx = 1;
        if(nums.length == 0){
            
            return output;
        }
        while(endIdx < nums.length){
            if(nums[curr] + 1 == nums[endIdx]){
                curr++;
                endIdx++;
            }else{
                StringBuilder sb = new StringBuilder();
                
                sb.append(nums[startIdx]);
                if(startIdx != curr){
                    sb.append("->");
                    sb.append(nums[curr]);
                }
                output.add(sb.toString());

                startIdx = endIdx;
                curr = startIdx;
                endIdx ++; 
            }
        }
        StringBuilder b = new StringBuilder();
        b.append(nums[startIdx]);
        if(startIdx != curr){
            b.append("->");
            b.append(nums[curr]);
        }
          output.add(b.toString());  
            
            
        

        return output;
    }
    
}
```