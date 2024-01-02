# 6. -zigzag

머리가 안돌아가서 쉽지 않았다.
https://leetcode.com/problems/zigzag-conversion/?envType=study-plan-v2&envId=top-interview-150

```java
class Solution {
    public String convert(String s, int numRows) {
        if(numRows < 2)
        {
            return s;
        }
        char[][] arr = new char[numRows][s.length()];
        String result = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < s.length(); j++){
                arr[i][j] = '&';
            }
        }

        for(int i = 0, row = 0, change = 1; i < s.length(); i++){
            arr[row][i] = s.charAt(i);
            if(row == numRows-1){
                    change = -1;
                }else if(row == 0){
                    change = 1;
                }
                row += change;
        }
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < s.length(); j++){
                if(arr[i][j] != '&'){
                    result+= arr[i][j];
                }
            }
        }

        return result;
    }
}
class Solution {
    public String convert(String s, int numRows) {
        int k = numRows * 2 - 2;
        StringBuilder res = new StringBuilder();

        if (numRows == 1 || numRows >= s.length()) return s;

        for (int i = 0; i < numRows; i++) {
            int left = i;
            int right = k - i;
            if (i == 0 || i == numRows - 1) right = s.length();
            for (int j = 0; j < s.length() / numRows + 1; j++) {
                if (left < s.length()) {
                    res.append(s.charAt(left));
                }

                if (right < s.length()) {
                    res.append(s.charAt(right));
                }

                left += k;
                right += k;
            }
        }

        return res.toString();
    }
}
```
