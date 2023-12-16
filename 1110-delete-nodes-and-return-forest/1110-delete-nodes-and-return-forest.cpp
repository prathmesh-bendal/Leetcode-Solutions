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
    TreeNode* solve(TreeNode* root,unordered_map<int,int> &mp,vector<TreeNode*> &ans)
    {
        if(root==NULL)
            return NULL;
        
        root->left=solve(root->left,mp,ans);
        root->right=solve(root->right,mp,ans);
        if(mp[root->val]==1)
        {
            if(root->left!=NULL)
            {
                ans.push_back(root->left);
            }
            if(root->right!=NULL)
            {
                ans.push_back(root->right);
            }
            
            return NULL;
        }
        
        return root;
            
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_map<int,int> mp;
        for(auto i:to_delete)
            mp[i]=1;
        
        
        vector<TreeNode*> ans;
        solve(root,mp,ans);
        
        if(mp[root->val]==0)
        {
            ans.push_back(root);
        }
        
        return ans;
        
        
    }
};