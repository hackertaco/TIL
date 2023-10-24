# 392. Is Subsequence
https://leetcode.com/problems/is-subsequence/?envType=study-plan-v2&envId=top-interview-150
어렵지는 않은 문제. 포인터를 달리 가져가면된다.
```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int slen= s.length();
        int tlen = t.length();
        int j=0;
        if(slen==0)
            return true;
        if(tlen==0)
            return false;
        for(int i=0;i<tlen;i++)
        {
            if(s.charAt(j)==t.charAt(i))
                j++;
            if(j==slen)
                return true;
        }
        return false;
    }
}

```