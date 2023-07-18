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
    
    void solve(TreeNode* root,TreeNode* &prev, int &ans)
    {
        
        if(root==NULL )
            return ;
        
        solve(root->left,prev,ans);
        ans=min(ans,abs(root->val- prev->val));
        prev=root;
        solve(root->right,prev,ans);
        
        
    }
    
        int getMinimumDifference(TreeNode *root)
        {
            TreeNode *prev = new TreeNode(INT_MAX);

            int ans = INT_MAX;
            solve(root, prev, ans);
            return ans;
        }
};