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
    
    void solve(TreeNode* root, int curr,int &ans)
    {
        if(root==NULL) return ; 
        if(root->left==NULL && root->right==NULL) 
        {
            ans+=curr*10+root->val;
            return ;
        }
        
        solve(root->left,curr*10+root->val,ans);
        solve(root->right,curr*10+root->val,ans);
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        if(root==NULL)  return 0;
        
        int ans=0;
        solve(root,0,ans);
        return ans;
        
    }
};