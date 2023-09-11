# 5. Palindrome Linked List
https://leetcode.com/explore/item/772

리스트를 반으로 나눴을 때 앞 뒤가 대칭이 되는지 안 되는지 체크하는 코드를 작성해야했다.

우선 전체 길이를 파악하고 반정도를 뒤집은 뒤에, 그를 나머지 반과 비교했다.
링크드 리스트 자체가 다루기가 까다로워서, 개인적으로는 시간이 오래걸렸다 ㅠㅠ



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
    public boolean isPalindrome(ListNode head) {
        ListNode lengthNode = head;
        ListNode fast = head;
         ListNode slow = head;
        ListNode right = null;
        int length = 0;
        while(lengthNode.next != null){
            lengthNode = lengthNode.next;
            length++;
        }
        
        for(int i=0; i<(length+1)/2; i++){
           
            ListNode left = new ListNode(slow.val, right);
            fast = fast.next;
            slow = slow.next;
            right = left;
        }
        // 위의 코드를 아래와 같이 풀어도 된다.
        // ListNode nextNode=null;
        // ListNode prev=null;
        // for(int i=0;i<cnt;i+=2){
        //     //System.out.println("i="+i);
        //     nextNode=head.next;
        //     head.next=prev;
        //     prev=head;
        //     head=nextNode;
        // }
        if(length % 2 ==0){
                fast = fast.next;
            }
        while(fast!=null && right!= null){
            
            if(fast.val != right.val){
                return false;
            }
            fast = fast.next;
            right = right.next;
        }
       
        return true;
    }
}
```