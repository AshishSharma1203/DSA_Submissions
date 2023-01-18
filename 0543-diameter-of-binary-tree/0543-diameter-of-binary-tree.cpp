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
    
    int height(TreeNode *root, int &ans)
    {
        
        if(root==NULL)
        {
            return 0;
        }
        int lh=height(root->left,ans);
        int rh=height(root->right,ans);
        
        int currdia=1+lh+rh;
        ans=max(ans,currdia);
        
        return 1+max(lh,rh);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans=0;
        int h=height(root,ans);
        return ans-1;
        
    }
};