4. Merge Two Linked List
https://leetcode.com/explore/item/771

이미 정렬되어있는 리스트를, 합치는 코드를 작성해야하는데 몹시 쉬웠다.
우리가 정렬 알고리즘을 배울 때 접하는 합병 정렬의 합병 과정이랑 동일하다. 
그냥 한 리스트가 null이 될 때까지 둘의 값을 비교한 뒤 차례대로 새 리스트에 넣어주었다.

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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode result = new ListNode();
        ListNode resultCopy = result;
        
        while(list1!=null && list2!=null ){
            if(list1.val > list2.val){
                resultCopy.next = new ListNode(list2.val);
                
                list2 = list2.next;
                
            }else{
                resultCopy.next = new ListNode(list1.val);
                list1 = list1.next;
            }
            resultCopy = resultCopy.next;
        }
        
        if(list1 !=null ){
            while(list1!=null){
                resultCopy.next = new ListNode(list1.val);
                list1 = list1.next;
                resultCopy = resultCopy.next;
            }
        }
        if(list2 !=null ){
            while(list2!=null){
                resultCopy.next = new ListNode(list2.val);
                list2 = list2.next;
                resultCopy = resultCopy.next;
            }
        }
        
        return result.next;
    }
}
```