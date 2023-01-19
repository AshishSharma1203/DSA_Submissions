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
        
        int lmax=solve(root->left,ans); // left side max value 
        int rmax=solve(root->right,ans); //right siide max value
        
        int lmx_root=max(root->val,(root->val+lmax)); //leftmax+root-value  path
        int rmx_root=max(root->val,(root->val+rmax)); //rightmax+root-value path
        int overall_sum=root->val+lmax+rmax;  // leftmax+rightmax+root->val path
        
        
        // now update ans with  max possible value of path 
        
        ans= max(ans,max(root->val,max(overall_sum,max(lmx_root,rmx_root))));
        
        // now return max of root node only  or rootnode +any left or side path 
        
        return max(root->val,root->val+max(lmax,rmax));
        
    }
    
    int maxPathSum(TreeNode* root) {
       int ans= INT_MIN;
      
        solve(root,ans);
        
        return ans;
        
    }
};