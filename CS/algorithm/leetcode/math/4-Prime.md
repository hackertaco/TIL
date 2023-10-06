# 4.   Count Primes

https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/

소수 개수를 찾는 문제. 처음에 나는 매번 비교하는 코드를 쳐서 time exceed가 떴다. 

그거 말고, 소수일 경우 그 소수로부터 파생되는 배수들을 모두 소수 아닌 수로 캐싱한다. 

```java
class Solution {
    public int countPrimes(int n) {
        boolean[] cache = new boolean[n];
        int count = 0;
        for(int i = 2; i<n; i++){
            if(cache[i] == false){
                count++;
                for(int j = 2; j*i < n; j++){
                    cache[j*i]=true;
                }
            }
            
        }
          return count;
    }
}

```