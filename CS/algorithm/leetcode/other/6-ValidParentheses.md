# 6. Valid Parentheses
https://leetcode.com/explore/item/721
스택 자료구조를 이용해서 풀었는데 무엇 때문인지 속도가 느렸다.
다른 사람들은 string을 charArray로 바꾸어 푼 것을 보았는데, 그 때문일까? 
```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for(int i = 0; i<s.length(); i++){
            if(!stack.isEmpty()){
                if(s.charAt(i) == ')'){
                if(stack.peek() == '('){
                    stack.pop();
                    continue;
                }
            }
            if(s.charAt(i) == ']'){
                if(stack.peek() == '['){
                    stack.pop();
                    continue;
                }
            }
            if(s.charAt(i) == '}'){
                if(stack.peek() == '{'){
                    stack.pop();
                    continue;
                }
            }
            }
            
            System.out.println(s.charAt(i));
            stack.push(s.charAt(i));
        }
        
        return stack.isEmpty();
    }
}

  
```
아래와같이 푸는 것이 더 빠르다. 
```java
class Solution {
    public boolean isValid(String s) {
        int i = -1;
        char[] stack = new char[s.length()];
        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[')
                stack[++i] = ch;
            else {
                if (i >= 0
                    && ((stack[i] == '(' && ch == ')')
                        || (stack[i] == '{' && ch == '}')
                        || (stack[i] == '[' && ch == ']')))
                    i--;
                else
                    return false;
            }
        }
        return i == -1;
    }
}
```