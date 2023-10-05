# 3.Roman To Integer
https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/878/
간단한 문제. 그냥 하라는대로 절차형 함수를 만들면 된다. 

```java
class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        int len = s.length();
        
        for(int i = 0; i < len; i++){
            char c = s.charAt(i);
            if(c == 'I'){
                if(i != len-1 && (s.charAt(i+1) == 'V' || s.charAt(i+1) == 'X') ){
                    sum -= 1;
                }else{
                    sum += 1;
                }
            }else if(c == 'V'){
                sum += 5;
            }else if(c == 'X'){
                if(i != len-1 && (s.charAt(i+1) == 'L' || s.charAt(i+1) == 'C') ){
                    sum -= 10;
                }else{
                    sum += 10;
                }
            }else if(c == 'L'){
                sum += 50;
            }else if(c== 'C'){
                if(i != len-1 && (s.charAt(i+1) == 'D' || s.charAt(i+1) == 'M') ){
                    sum -= 100;
                }else{
                    sum += 100;
                }
            }else if(c== 'D'){
                sum += 500;
                
            }else{
                sum += 1000;
            }
        }
        return sum;
    }
}
```