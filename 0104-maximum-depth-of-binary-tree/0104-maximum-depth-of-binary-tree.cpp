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
    
    void preorder(TreeNode *root, int &ans,int tempans)
    {

    if(root==NULL)
    {
        return ;
    }
        
        tempans++;
        ans=max(ans,tempans) ;
        preorder(root->left,ans,tempans);
        preorder(root->right,ans,tempans);
        
        
    }
    
    int maxDepth(TreeNode* root) {
      
     int ans=0;
     
    if(root==NULL)
    {
        return ans;
    }
    
    preorder(root,ans,0);
        
    return ans;
        
        
    }
};