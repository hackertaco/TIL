# 4. Binary Tree Level Order Traversal
https://leetcode.com/explore/item/628

너비우선 원칙을 응용해서 풀 수 있는 문제다. 
list 안에 같은 level끼리 모아둔 list를 넣는 문제다. 

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        
        List<List<Integer>> list = new ArrayList<>();
        if(root == null){
            return list;
        }
        queue.offer(root);
        while(!queue.isEmpty()){
            int levelNum = queue.size();
            List<Integer> miniList = new ArrayList<>();
            for(int i = 0; i< levelNum; i++){
                if(queue.peek().left != null)
                    queue.offer(queue.peek().left);
                if(queue.peek().right != null)
                    queue.offer(queue.peek().right);
                miniList.add(queue.poll().val);
            }
            list.add(miniList);
        }
        
        return list;
    }
   
}
```
```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        return recurse(root, 0, new ArrayList<>());
    }

    private List<List<Integer>> recurse(TreeNode root, int level, List<List<Integer>> res) {
        if (root == null) return res;
        if (res.size() == level) res.add(new ArrayList<>());
        res.get(level).add(root.val);
        recurse(root.left, level + 1, res);
        recurse(root.right, level + 1, res);
        return res;
    }
}
```
위와 같이 재귀로 풀 수도 있다.