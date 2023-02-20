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
     bool flag=false;
     TreeNode* i1=NULL,*i2=NULL,*prev;
    
   void  solve(TreeNode* curr)
       
    {
        if(curr==NULL) return ;
        
        solve(curr->left);
        
        // check if it is not the extreme left leaf node 
       
            if(curr->val<prev->val)
            {
              if(flag==false)  // this is first irregurality in inorder ascending order
              {
                  i1=prev;
                  i2=curr;
                  flag=true;
                
              }
                
                else    // this is second  irregurality in inorder ascending order
                {
                    i2=curr;
                    return ; 
                }
            }
       prev=curr;
        
        solve(curr->right);
        
    }
    
   void recoverTree(TreeNode* root) {
        TreeNode*curr;
        prev = new TreeNode(INT_MIN);
        curr=root;
        solve(curr);
        swap(i1->val,i2->val);
        return; 
        
    }
};