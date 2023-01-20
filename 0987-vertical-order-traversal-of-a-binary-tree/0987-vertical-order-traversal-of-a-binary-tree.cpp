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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root==NULL)
            return ans;
        
        // node,x,y
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        // x,y,nodes 
        
        map<int,map<int,multiset<int>>> m;
        
        q.push({root,{0,0}});
        
        while(q.empty()==false)
        {
            auto temp=q.front();
            q.pop();
            
            TreeNode* curr=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            
            m[x][y].insert(curr->val);
            
            if(curr->left)
            {
                q.push({curr->left,{x-1,y+1}});
            }
            if(curr->right)
            {
                q.push({curr->right,{x+1,y+1}});
            }
            
        }
        
        for(auto a:m)
        {
        vector<int> temp;
            for(auto b:a.second)
            {
                for(auto c:b.second)
                {
                    temp.push_back(c);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};