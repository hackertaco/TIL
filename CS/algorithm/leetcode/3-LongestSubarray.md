## 3. Longest Substring Without Repeating Characters

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150

sliding window 방식으로, 중복 되는 것을 차례차례 지워나간다. 

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        List<Character> list = new ArrayList<>();
        char[] str = s.toCharArray();
        int max = list.size();

        for(int i = 0; i < str.length; i++){
            if(list.indexOf(str[i]) > -1){
                int curr = list.indexOf(str[i]);
                int len = list.size();
                max = Math.max(list.size(), max);
                
                List<Character> newLs = new ArrayList<>();
                for(int j = curr+1; j < len; j++){
                    newLs.add(list.get(j));
                }
                list = newLs;
            }
            list.add(str[i]);
        }
        return Math.max(list.size(), max);
    }
}
// 위보다 아래가 속도가 더 빠르다. int 배열과 askii 코드를 잘 이용해야한다.
class Solution {

    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int[] b = new int[128];
        int max = 0;
        int l = -1;
        for (int i = 0; i < n; i++) {
            l=Math.max(l,b[s.charAt(i)]);
            max=Math.max(max,i-l+1);
            b[s.charAt(i)]=i+1;
        }
        return max;
    }
}
```
