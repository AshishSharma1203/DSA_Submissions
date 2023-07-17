/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    
    bool solve(TreeNode* curr,long min ,long max)
    {

        if(curr==NULL)
            return true;
        
        // if(curr->val>= max && curr->val<=max)
        //     return false;
        
        return (curr->val<max && curr->val>min )&& solve(curr->left,min,curr->val)&& solve(curr->right,curr->val,max);
    
    }
    
        bool isValidBST(TreeNode *root)
        {

           	// approach 1; at each node find the max  element of left and min  elemenet of right if(curr_val < min ||curr_val>max) returnn false else recursively check for other nodes 

            
            // approach 2; form inorder and then whether its increaesing or noot 
            
            // approach 3:
            
            if(root==NULL || (root->left==NULL &&root->right==NULL))
                return true;
            
            long  min=LONG_MIN , max=LONG_MAX;
            
            return solve(root,min,max);
            
        }
};