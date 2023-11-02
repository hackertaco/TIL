# 100. is same tree
https://leetcode.com/problems/same-tree/description/?envType=study-plan-v2&envId=top-interview-150

트리가 서로 같은지 확인하는 코드를 작성해야한다. 좀 더 깨끗하게 할 수도 있었을것같은데 우선 그냥 재귀로 하는 방법밖에 생각이 안나서 작성했고 풀었다. 
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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null){
            if(q != null){
                return false;
            }
            return true;
        }
        if(q == null){
           if(p != null){
                return false;
            }
            return true; 
        }
        if(p.val == q.val){
            return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        }
        return false;
    }
}
```