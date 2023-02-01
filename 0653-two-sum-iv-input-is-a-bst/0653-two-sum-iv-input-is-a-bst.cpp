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
    
    void solve (TreeNode* curr, int k,unordered_set<int> &s,bool &ans)
    {
        if(curr==NULL) return ;
        if(s.find(k-curr->val)!=s.end())
        {
            ans=true;
            return ;
        }
        else {
            s.insert(curr->val);
        }
        solve(curr->left,k,s,ans);
        solve (curr->right,k,s,ans);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        unordered_set<int> s;
        bool ans=false;
        solve(root,k,s,ans);
        
        return ans; 
        
    }
};