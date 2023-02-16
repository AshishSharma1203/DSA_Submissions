/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     
        TreeNode * curr=root;
        TreeNode* ans=NULL;
        int a=p->val,b=q->val;
        while(curr!=NULL)
        {
            if(curr->val==a || curr->val==b)  
            {
                return curr;
            }
            else if((curr->val>a && curr->val<b) || (curr->val<a && curr->val>b) )  return curr;
            
            else if (curr->val>a && curr->val >b) curr=curr->left;
            else curr=curr->right;
        }
        
        return ans; 
    }
};