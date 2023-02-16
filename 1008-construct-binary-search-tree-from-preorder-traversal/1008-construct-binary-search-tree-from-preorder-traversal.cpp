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
    
    TreeNode* solve(vector<int> &preorder, int start,int end)
    {
        if(start>end)   return NULL;
        
        TreeNode* root=new TreeNode(preorder[start]);
        int index=start+1;
        while(index<=end && preorder[index]<preorder[start])
        {
            index++;
        }
        root->left=solve(preorder,start+1,index-1);
        root->right=solve(preorder,index,end);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       if(preorder.size()==0) return NULL;
        int start=0,end=preorder.size()-1;
        TreeNode* root=solve(preorder,start,end);
        
        return root;
    }
};