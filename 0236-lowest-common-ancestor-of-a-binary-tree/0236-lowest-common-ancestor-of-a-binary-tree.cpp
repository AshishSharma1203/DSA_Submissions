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
    bool find(TreeNode* root, TreeNode*p)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->val==p->val)
        {
            return true;
        }
        return find(root->left,p)  || find(root->right,p) ;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // taking left =0 &  right=1;
        
        bool flag1,flag2;
        
        TreeNode* ans=NULL;
        TreeNode*curr= root;
       
       
        
        while(curr!=NULL)
        {
             if(curr->val==p->val || curr->val==q->val)   return curr;
           
             flag1=find(curr->left,p);
             flag2=find(curr->left,q);
            
            if(flag1==0 && flag2==0)
            {
                curr=curr->right;
            }
            else if(flag1==1 && flag2==1)
            {
                curr=curr->left;
            }
            else if(flag1==1 && flag2==0 ||flag1==0 && flag2==1)
            {
                return curr;
            }
        }
        
        return curr;
        
    }
};