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
    void dfs_level(TreeNode* root,int curr,unordered_map<int,int> &level)
    {
        if(root==NULL)
            return;
        level[root->val]=curr;
        
        dfs_level(root->left,curr+1,level);
        dfs_level(root->right,curr+1,level);
    }
    int dfs_height(TreeNode* root,unordered_map<int,int> &height)
    {
        if(root==NULL)
            return -1;
        
        int lh=dfs_height(root->left,height);
        int rh=dfs_height(root->right,height);
        
        height[root->val]=max(lh,rh)+1;
        return height[root->val];
        
        
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int,int> level;
        unordered_map<int,int> height;
        
        
        dfs_level(root,0,level);
        
        dfs_height(root,height);
        
        
        int n=level.size();
        
        vector<vector<int>> mp(n,vector<int>(2,-1));
        
        for(auto i:level)
        {
            int l=i.second;
            int node=i.first;
            if(height[node]>mp[l][0])
            {
                mp[l][1]=mp[l][0];
                mp[l][0]=height[node];
            }
            else if(height[node]>mp[l][1])
            {
                mp[l][1]=height[node];
            }
                
        }
        
        int m=queries.size();
        vector<int> ans(m);
        
        for(int i=0;i<m;i++)
        {
            int q=queries[i];
            int curr=level[q];
            
            if(mp[level[q]][0]==height[q])
            {
                if(mp[level[q]][1]!=-1)
                {
                    curr+=mp[level[q]][1];
                }
                else
                {
                    curr--;
                }
            }
            else
            {
                curr+=mp[level[q]][0];
            }
            ans[i]=curr;
        }
        return ans;
    }
};