## 8. Longest Prefix
가장 긴 접두어를 구하는 문제. 
나는 제일 정석대로 풀었는데 역시나 시간이 빠르게 나오지는 않았다.



```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        int shortestLength = Integer.MAX_VALUE;
        int shortestIdx = 0;
        for(int i =0; i<strs.length; i++)
        {
            shortestLength = Math.min(strs[i].length(), shortestLength);
            if(shortestLength == strs[i].length()){
                shortestIdx = i;
            }
        }
        char[] shortest = strs[shortestIdx].toCharArray();
        
        int j = 0;
        int p = 0;
        while(j <  shortestLength )
        {
            
            for(p=0; p < strs.length; p++){
                if(strs[p].charAt(j) != shortest[j]){
                    break;
                }else{
                    continue;
                }
            }
            System.out.println(p);
            if(p<strs.length && strs[p].charAt(j) != shortest[j]){
                    break;
                }
            j++;
        }
        
        return strs[shortestIdx].substring(0, j);
    }
}
```

![Alt text](image-8.png)

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) return "";
        String prefix = strs[0];
        for(int i=1;i<strs.length;i++){
            while(strs[i].indexOf(prefix) != 0){
                prefix = prefix.substring(0,prefix.length()-1);
            }
        }
        return prefix;
    }
}
```

너무 간단하게 풀었고, 시간도 빠르다.

내가 이렇게 풀지 못한 이유는 indexOf가 string 단위로 가능한지 몰랐기 때문이다.

알고리즘을 계속 풀면서 느끼는 것은 단순화하는게 정말 중요하다는 것이다.
