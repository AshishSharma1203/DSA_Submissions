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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root==NULL)
        {
            return ans;
        }
        bool flag=false;
        queue<TreeNode * > q;
        
    q.push(root);
        
        while(q.empty()==false)
        {
            
           
            int size=q.size();
          
            vector<int> level_nodes;
          
            for(int i=0;i<size;i++){
                 TreeNode* curr= q.front();
                  q.pop();
                level_nodes.push_back(curr->val);
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
            
            if(flag==true)
            {
                reverse(level_nodes.begin(),level_nodes.end());
                ans.push_back(level_nodes);
            }
            else{
                ans.push_back(level_nodes);
            }
            flag=!flag;
            
        }
        
        return ans; 
        
    }
};