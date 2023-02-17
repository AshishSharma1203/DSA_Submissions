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
    
    bool solve(TreeNode* root,long low,long high)
    {
        if(root==NULL) return true;
    
    // if(root->left==NULL && root->right==NULL)
    //     return true;
    
        
        bool left_flag=solve(root->left,low,root->val);
        bool right_flag=solve(root->right,root->val,high);
        
        return left_flag && right_flag && (root->val>low && root->val<high);
        
    }
    
    bool isValidBST(TreeNode* root) {
     long low=LONG_MIN,high=LONG_MAX;
    
        bool ans=solve(root,low,high);
        
        return ans; 
    }
};