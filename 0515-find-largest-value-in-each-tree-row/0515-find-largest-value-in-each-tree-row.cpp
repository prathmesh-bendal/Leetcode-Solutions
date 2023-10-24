/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> v;
        if(root==NULL)
            return v;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.size()>0)
        {
            int sz=q.size();
            int mx=INT_MIN;
            
            while(sz--)
            {
                TreeNode* u=q.front();
                q.pop();
                mx=max(mx,u->val);
                if(u->left!=NULL)
                    q.push(u->left);
                
                if(u->right!=NULL)
                    q.push(u->right);
            }
            
            v.push_back(mx);
        }
        return v;
    }
};