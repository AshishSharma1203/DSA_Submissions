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
    
    void solve(TreeNode* root, vector<int> &preorder)
    {
        if(root==NULL)  return ;
        preorder.push_back(root->val);
        solve(root->left,preorder);
        solve(root->right,preorder);
    }
    
    void flatten(TreeNode* root) {
        
        if(root==NULL) return ;
        
        vector<int> preorder;
        solve(root,preorder);
        TreeNode* curr=root;
        
        for(int i=0;i<preorder.size()-1;i++)
        {
            curr->left=NULL;
            curr->right=new TreeNode (preorder[i+1]);
            curr=curr->right;
        }
        
        return ;
    }
};