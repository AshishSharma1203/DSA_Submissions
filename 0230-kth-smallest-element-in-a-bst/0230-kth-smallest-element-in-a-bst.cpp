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
    
    void solve(TreeNode* curr, int &count, int k,int &ans)
    {
        if(curr==NULL)
            return ;
        
        solve(curr->left,count,k,ans);
        count++;
        if(count==k)
        {

        ans=curr->val;
            return ;
        }
        solve(curr->right,count,k,ans);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
      
        int count=0, ans=0;
        
    solve(root,count,k,ans);
        
        return ans;
        
    }
};