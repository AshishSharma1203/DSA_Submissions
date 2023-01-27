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
    
    void left_h(TreeNode*curr,int &lh)
    {
        if(curr==NULL)
            return ;
        lh++;
        left_h(curr->left,lh);
        
    }
    
    void right_h(TreeNode * curr,int &rh)
    {
        if(curr==NULL)
            return ;
        rh++;
        
           right_h(curr->right,rh);
            
        
       
    }
    
    int solve(TreeNode * curr)
    {
        int lh=0;
        left_h(curr,lh);
        int rh=0;
        right_h(curr,rh);
        
        if(lh==rh)
            return pow(2,lh)-1;
        else 
        {
            return 1+solve(curr->left)+solve(curr->right);
        }
        
    }
    
    int countNodes(TreeNode* root) {
        int ans=0;
        if(root==NULL)
            return ans;
//         int lh=0,rh=0;
     
//         void left_h(root,lh);
//         void right_h(root,rh);
        
//         if(rh==lh)
//             return pow(2,lh)-1;
        ans=solve(root);
        return ans;
        
        
    }
};