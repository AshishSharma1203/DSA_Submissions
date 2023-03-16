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
    
    
    
    TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int inStart,int inEnd,int postStart,int postEnd, unordered_map<int,int> &mp)
    {
        if(inStart>inEnd || postStart>postEnd)  return NULL;
        
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int index=mp[root->val];
        int elements=inEnd-index;
        root->left=solve(inorder,postorder,inStart,index-1,postStart,postEnd-elements-1,mp);
        root->right=solve(inorder,postorder,index+1,inEnd,postEnd-elements,postEnd-1,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
       
         unordered_map<int,int> mp;
        int n=inorder.size(),m=postorder.size();
        
        for(int i=0;i<n;i++)
        {
            
             mp.insert({inorder[i],i});
        }
        
        int inStart=0,inEnd=n-1,postStart=0,postEnd=m-1;
        
        TreeNode*root= solve(inorder,postorder,inStart,inEnd,postStart,postEnd,mp);
        
        return root;
        
    }
};