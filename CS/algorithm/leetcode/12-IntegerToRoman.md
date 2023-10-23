## 12. Integer To Roman
숫자를 로마자로 바꾸는 코드. 어렵지는 않았는데 string에서 배열로 넘나드는 과정에서 분명 시간적 손해가 있었을 것 같다. 더 좋은 방법은 그냥 애초에 모든 경우의 수를 배열에 집어넣고 비교해가며 큰 숫자부터 num에서 빼는 방법이다.
```java
class Solution {
    public String intToRoman(int num) {
        int[] mid = new int[4];
        String[] result = new String[4];
        int multi = 1;
        Map<Integer, String> map = new HashMap<>();
        map.put(1, "I");
        map.put(5, "V");
        map.put(10, "X");
        map.put(50, "L");
        map.put(100, "C");
        map.put(500, "D");
        map.put(1000, "M");
        for(int i = 3; i>= 0; i--) {
            mid[i] = num % 10;
            num /= 10;
        }

        for(int i = 3; i>= 0; i--){
            if(mid[i]==0){
                result[i] = "";
            }
            if(mid[i]==4){
                result[i] = map.get(multi)+map.get(multi*5);
            }else if(mid[i]==9){
                result[i] = map.get(multi)+map.get(multi*10);
            }else{
                if(mid[i] >= 5){
result[i] = map.get(multi*5)+map.get(multi).repeat(mid[i]-5);
                }else{
    result[i] = map.get(multi).repeat(mid[i]);
                }
                
            }

            multi*=10;
        }
        return String.join("", result);
    }
}
```