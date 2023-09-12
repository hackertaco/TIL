# 6. Linked List Cycle
리스트에 사이클이 있는지 없는지를 판별해야한다.

나는 또 너무 어렵게 생각했다. 일단 순회하며 같은 요소가 있는지, 없는지 파악하고 
그것들끼리의 길이를 구해서 같은지를 판단하면 true를 return 했다.

하지만 굳이 그럴 필요가 없었다.

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode s = head;
        ListNode fast = head;
        boolean result = false;
        int len = 0;
        while(s != null  && len < 10000){
            s = s.next;
            len++;
        }
        if(s == null){
            return false;
        }
        while(fast != null ){
            
            if(checkCycle(fast)){
                return true;
            }else{
                fast = fast.next;
                
            }
        }
        
        return result;
        
            
    }
    
    public boolean checkCycle(ListNode head)
    {
        ListNode fast = head.next;
        ListNode stand = head;
        int length = 1;
        while(fast != null && length < 10000)
        {
            
            if(fast.val == stand.val){
                for(int i = 0; i< length+1; i++){
                    
                    if(fast !=null && fast.val == stand.val){
                        System.out.println(fast.val);
                        fast = fast.next;
                        stand = stand.next;
                    }else{
                        
                        return false;
                    }
                }
                
                return true;
            }
            length++;
            fast = fast.next;
        }
        
        return false;
    }
}
```

처음의 코드는 정말 될대로 돼라 느낌의 코드여서, 너무 지저분하다.
사실 그렇게 풀 필요는 없고, 그냥 아래와 같이 하나는 한칸씩, 하나는 두칸씩 움직이게 만들면 되었던 문제다. 


```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode fast = head, slow = head;
        while(fast != null && fast.next != null){
            slow=slow.next;
            fast=fast.next.next;
            if(slow == fast)
                return true;
        }
        return false;
    }
}
```