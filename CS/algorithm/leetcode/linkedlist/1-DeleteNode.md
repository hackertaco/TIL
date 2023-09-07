# 1. Delete Node in a Linked List
https://leetcode.com/explore/item/553

상당히 간단했던 문제.
리스트가 주어지지 않은 상태에서, 노드를 지울 수 있는 방법을 생각하면 된다.

다음 노드의 주소와 값 정보를 모두 복사해오면 된다.
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
       node.val = node.next.val;
        node.next = node.next.next;
    }
}
```
