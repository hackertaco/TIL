# 58. Length of Last word

https://leetcode.com/problems/length-of-last-word/
toCharArray를 사용하면 시간이 훨씬 빨라진다.
예전의 경험을 토대로 이번에는 해당 메소드를 사용했다.

마지막 단어의 길이를 구하면 되는 문제라, 띄어쓰기만 주의하면 된다는 생각으로 진행했다. 시간이 0ms 나와서 뿌듯했던 문제!

```java
class Solution {
    public int lengthOfLastWord(String s) {
        char[] ch = s.toCharArray();
        int count = 0;
        for(int i = ch.length-1; i >= 0; i-- ){
            if(ch[i] == ' '){
                if(count == 0){
                    continue;
                }else{
                    break;
                }
            }
            count++;
        }
        return count;
    }
}
```
