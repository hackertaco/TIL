## 2. FBV
https://leetcode.com/explore/featured/card/top-interview-questions-easy/96/sorting-and-searching/774/

간단하게 이진 탐색하는 문제다.
```java
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        while(start < end){
            int mid = start + (end-start) / 2;
            if(!isBadVersion(mid)) {
                start = mid + 1;
            }else{
                end = mid;
            }
            
        }
        return start;
    }
    
     
}
```