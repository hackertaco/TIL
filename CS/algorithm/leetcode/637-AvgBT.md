## -637. Avg of Levels in BT
https://leetcode.com/problems/average-of-levels-in-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

BFS를 이용하는 문제. 
queue에서 하나씩 빼서 그 아래 트리를 집어넣고 계산
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> list = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>(List.of(root));

        while(q.size() > 0){
            double qlen = q.size(), row = 0;
            for(int i = 0; i<qlen; i++){
                TreeNode curr = q.poll();
                row += curr.val;
                if(curr.left != null) q.offer(curr.left);
                if(curr.right != null) q.offer(curr.right);
            }
            list.add(row/qlen);
        }
        return list;
    }
}
```