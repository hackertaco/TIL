## 383. Ransom Note
https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150


이건 문제는 쉽지만 빠르게 하기는 어렵다.
하지만 패턴이 있으므로 잘 파악하면 좋다. 

나는 첫번째와 같이 for문을 두개 돌렸지만, 하나로 끝내는 게 더 빠르다. (당연히)


```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> map = new HashMap<>();
        char[] magazineArr = magazine.toCharArray();
        char[] ransom = ransomNote.toCharArray();
        for(char mag:magazineArr){
            if(map.get(mag) != null){
                int val = map.get(mag);
                map.put(mag, val+1);
            }else{
                map.put(mag, 1);
            }
        }
        for(char ran: ransom){
            if(map.get(ran) == null){
                return false;
            }else{
                int val = map.get(ran);
                System.out.println(ran);
                map.put(ran, val-1);
                System.out.println(val);
                if(map.get(ran) < 0){
                    return false;
                }
            }
        }
        return true;

    }
}
```
아래와 같이 진행하면 훨씬 빠르다. askii 를 이용해야한다.
```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] indexMap = new int[128];
        for (char c : ransomNote.toCharArray()) {
            int sourceIndex = magazine.indexOf(c, indexMap[c]);

            if (sourceIndex == -1) {
                return false;
            }
            indexMap[c] = sourceIndex + 1;
        }
        return true;
    }
}
```