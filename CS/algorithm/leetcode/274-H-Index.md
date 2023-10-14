## 274. H-index
https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

즉 H보다 크거나 같은 수가 h개 이상 있어야한다. 

나는 우선 정렬 후 풀었는데 속도가 제일 빠르지는 않았다. 정렬 자체가 빠르지는 않기 때문이다.
```java
class Solution {
    public int hIndex(int[] citations) {
        int result = 0;
        
        Arrays.sort(citations);

        if(citations.length <= citations[0]){
            return citations.length;
        }
    
        for(int i = 1; i < Math.min(citations.length, citations[citations.length-1]+1); i++){
            if(citations[citations.length-i] >= i){
                result = i;
            }
        }
        return result;
    }
}
```
아래처럼 풀 수도 있다. 더 빠른 알고리즘이다.
```java
class Solution {
    public int hIndex(int[] citations) {
        int n= citations.length;
        int count[]=new int[n+1] ;
        for(int i=0;i<n;i++){
            if(citations[i]>n){
                count[n]++;
            }else{
               count[citations[i]]++;

            }
        }
        int ans=0;
          for(int i=n;i>=0;i--){
              ans+=count[i];
              if(ans>=i){
                  return i;
              }
        }
        return 0;
    }
}
```