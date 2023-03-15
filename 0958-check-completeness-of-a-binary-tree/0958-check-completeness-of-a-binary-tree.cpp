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
    bool isCompleteTree(TreeNode* root) {
        
        // perform level order traversal and check whether all nodes are present or not
        
        if(root==NULL ||(root->left==NULL && root->right==NULL))  return true;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.empty()==false)
        {
           TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL) break;
            else
            {
                 q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        // check if there is still any non NULL node present in the queue  
        
        while(q.empty()==false)
        {

        TreeNode*curr=q.front();
            q.pop();
            if(curr!=NULL) return false;
            
        }
        
        return true; 
        
    }
};