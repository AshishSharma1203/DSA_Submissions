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
    
    bool check(TreeNode* curr1, TreeNode * curr2)
    {
        if(curr1==NULL || curr2==NULL )
        {
            return curr1==curr2;
        }
        
        return curr1->val==curr2->val && check(curr1->left, curr2->right) && check(curr1->right,curr2->left);
        
    }
    
    bool isSymmetric(TreeNode* root) {
       if(root==NULL)
       {
           return true;
       }
        bool ans= check(root->left, root->right);
        
        return ans; 
    }
};