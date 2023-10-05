# Reverse Bits
https://leetcode.com/explore/item/648
앤드연산과 비트연산으로 비트 뒤집기

그냥 Integer.reverse(n)해도 잘된다. 
```java
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int result = 0;
        for(int i = 0; i<32; i++){
            result <<= 1;
             if((n&1) == 1) result++;
            n = n>> 1;
        }
       return result;
    }
    public int reverseBits(int n) 
    {
          return Integer.reverse(n); 
    }
}
```