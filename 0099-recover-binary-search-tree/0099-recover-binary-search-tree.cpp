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
    
    void solve(TreeNode* root,vector<TreeNode*> &inorder)
    {
        if(root==NULL)  return ; 
        solve(root->left,inorder);
        inorder.push_back(root);
        solve(root->right,inorder);
    }
    
    void recoverTree(TreeNode* root) {
        if(root==NULL ||( root->left==NULL && root->right==NULL)) return ;
        vector<TreeNode*> inorder;
        solve(root,inorder);
        
      TreeNode* first,*second;
        
           for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]->val > inorder[i+1]->val){
                first = inorder[i];
                break;
            }
        }
        for(int i=inorder.size()-1;i>=0;i--){
            if(inorder[i]->val < first->val){
                second = inorder[i];
                break;
            }
        }
        swap(first->val,second->val);
     
        return ;
        
    }
};