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
    
    TreeNode* solve(vector<int>& inorder,int inStart,int inEnd, vector<int>& postorder,int postStart,int                           postEnd,  unordered_map<int,int> &m)
         
    {
 
        if(inStart>inEnd || postStart>postEnd)  return NULL;
        
        TreeNode* root=new TreeNode (postorder[postEnd]);
        
        int index=m[root->val];
        int element=inEnd-index;
        
        root->left=solve(inorder,inStart,index-1,postorder,postStart,postEnd-element-1,m);
        root->right=solve(inorder,index+1,inEnd,postorder,postEnd-element,postEnd-1,m);
        
        
        return root;
    
    
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int inStart=0,inEnd=inorder.size()-1,postStart=0,postEnd=postorder.size()-1;
        
        unordered_map<int,int> m;
        
        for(int i=0;i<=inEnd;i++)
            m.insert({inorder[i],i});
        
        TreeNode* root=solve(inorder,inStart,inEnd,postorder,postStart,postEnd,m);
        
        return root;
        
    }
};