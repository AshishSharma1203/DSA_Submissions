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
    void flatten(TreeNode* root) {
        
        if(root==NULL || (root->left==NULL && root->right==NULL) ) return;  
        
        TreeNode * curr= root;
        
        while(curr!=NULL) 
        {
            if(curr->left==NULL)
            {
                curr=curr->right;
            }
            else
            {
                TreeNode* precedecessor= curr->left;
                while(precedecessor->right!=NULL) 
                {
                    precedecessor=precedecessor->right;
                }
                precedecessor->right=curr->right;
                TreeNode* temp=curr->left;
                curr->left=NULL;
                curr->right=temp;
                curr=curr->right;
            }
        }
        return ;
    }
};