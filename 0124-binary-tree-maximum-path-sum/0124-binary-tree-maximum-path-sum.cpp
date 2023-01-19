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
    
    int solve(TreeNode* root,int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int lmax=solve(root->left,ans);
        int rmax=solve(root->right,ans);
        
        int lmx_root=max(root->val,(root->val+lmax));
        int rmx_root=max(root->val,(root->val+rmax));
        int overall_sum=root->val+lmax+rmax;
        
     ans= max(ans,max(root->val,max(lmx_root,max(rmx_root,overall_sum))));
         // ans=max(ans ,(max(root->val,lmax+rmax+root->val)));
        // return root->val + max(lmax,rmax);
        return max(root->val,root->val+max(lmax,rmax));
        
    }
    
    int maxPathSum(TreeNode* root) {
       int ans= INT_MIN;
      
        solve(root,ans);
        
        return ans;
        
    }
};