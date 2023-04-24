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
class Pair{
    int count;
    TreeNode node;
    
    Pair(TreeNode node,int count)
    {
        this.node=node;
        this.count=count;
    }
}
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        
        
        List<Integer> ans=new ArrayList<>();
        if(root==null)
            return ans;
        
        Stack<Pair> s=new Stack<>();
        
        s.push(new Pair(root,1));
        
        while(!s.empty())
        {
            Pair p=s.pop();
            if(p.count==1)
            {
                ans.add(p.node.val);
                p.count++;
                s.push(p);
                if(p.node.left!=null)
                {
                    s.push(new Pair(p.node.left,1));
                }
            }
            else if(p.count==2)
            {
                p.count++;
                s.push(p);
                if(p.node.right!=null)
                {
                    s.push(new Pair(p.node.right,1));
                }
            }
            else
            {
                
            }
        }
        return ans;
    }
}