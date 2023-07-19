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
    
    int solve(TreeNode* root,long int sum,int target)
    {
        
        if(root==NULL)
            return 0;
        
        return( sum+root->val==target)+ solve(root->left,sum+root->val,target)+ solve(root->right,sum+root->val,target)
;        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        
        return solve(root,0,targetSum)+ pathSum(root->left,targetSum)+ pathSum(root->right,targetSum);
    }
};