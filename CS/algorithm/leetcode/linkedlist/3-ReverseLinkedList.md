## 3. Reverse Linked List
https://leetcode.com/explore/item/560

링크드리스트가 자칫하면 cycle이 자꾸나와서 세심해야한다.
나는 다음 단계의 노드와 현 노드를 계속 이어주고 재대입하고를 반복했다.



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
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode right = new ListNode(head.val);
        ListNode left = new ListNode(head.next.val);
        int length =0;
        
        while(head.next != null){
            left.next = right;
            right = left;
            if(head.next.next == null){
                left = new ListNode();
            }else{
                left = new ListNode(head.next.next.val);
            }
            
            head = head.next;
            
        }
        return right;
       
    }
}
```
```java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode temp=null;
        while(head!=null){
            ListNode next=head.next;
            head.next=temp;
            temp=head;
            head=next;
        }
        return temp;
        
    }
}
```