## 2. Remove Nth Node From End of List
https://leetcode.com/explore/item/603

중간 연결을 끊어야하는 알고리즘. 

우선 나는 전체 길이를 잰 다음, 길이 기준으로 n 위치를 찾고, 그 위치에서 오른쪽 리스트와 왼쪽 리스트를 연결하는 코드를 짰다.

너무 헷갈렸다..! 

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode newNode = new ListNode(head.val, head.next);
        ListNode right = new ListNode(head.val, head.next);
        int length = 0;
        while(newNode.next != null){
            newNode = newNode.next;
            length++;
        }
        for(int i = 0; i < length-n+2; i++){
            right = right.next;
        }
        for(int i = length-n; i >= 0; i--){
            ListNode left = new ListNode(head.val, head.next);
            for(int j = i-1; j >= 0; j--) {
                left = left.next;
            }
            left.next = right;
            right = left;
            
            
        }
        return right;
        
    }
}
```

```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode start  = new ListNode();
        // start.next = head;
        ListNode slow = head;
        ListNode fast = head;
        for(int i = 1; i <= n; i++){
            
            fast = fast.next;
        }
        if(fast == null){
                return head.next;
            }
        while(fast.next != null){
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next; 
        return head;
    }
}
```

이와 같이 복제본이 움직이면서 head에 변화를 주는 것도 가능하다. 