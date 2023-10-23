## 151. Reverse Words
https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
단어 순서만 바꿔 보여주는 문제. reverse를 두번씩해서 공간 복잡도를 최대한 낮춘다.
```java
class Solution {
    public String reverseWords(String s) {
        // reverse the whole string
        char[] str = reverse(s.toCharArray(), 0, s.length() - 1);
        // reverse each sub string
        // delete leading and trailing spaces
        // leave only one space for interval
        int start = 0;
        int end = 0;
        for(int i = 0; i < str.length; i++) {
            if (str[i] != ' ') {
                str[end++] = str[i];
            } else if (i > 0 && str[i - 1] != ' ') {
                reverse(str, start, end - 1);
                str[end++] = str[i];
                start = end;
            }
        }
        // reverse the tail word if necessary
        reverse(str, start, end - 1);
        return new String(str, 0, end).trim();
    }

    private char[] reverse(char[] array, int start, int end) {
        while (start < end) {
            char c = array[start];
            array[start++] = array[end];
            array[end--] = c;
        }
        return array;
    } 
}

```
아래 코드는 시간이 몹시 길게 나오므로 진행하지 않는 것이 좋을듯하다.

```java
class Solution {
    public String reverseWords(String s) {
        String[] arr = s.strip().split(" ");
        List<String> list = new ArrayList<>();
        for(int i = arr.length-1; i>=0; i--){
            if(arr[i].isBlank()) continue;
            System.out.println(arr[i]);
            list.add(arr[i]);
        }
        return list.stream().map(n->String.valueOf(n))
                .collect(Collectors.joining(" "));
    }
}
```