# 1. FizzBuzz
굉장히 쉬운 문제. 3과 5의 배수일 때는 fizzbuzz, 3의 배수면 fizz 5의 배수면 buzz를 결과값에 넣어야한다.
if문 위치만 잘 조정하면 된다.
```java
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> result = new ArrayList<>();
        
        for(int i = 0; i< n; i++)
        {
            if((i+1)%3==0 && (i+1)%5 == 0){
                result.add(i, "FizzBuzz");
                continue;
            }else if((i+1)%3==0){
                result.add(i, "Fizz");
            }else if((i+1)%5 == 0){
                result.add(i, "Buzz");
            }else{
                result.add(i, Integer.toString(i+1));
            }
        }
        return result;
    }
}
```