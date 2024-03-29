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
    
    vector<TreeNode*> solve(int start, int end)
    {
        vector<TreeNode*> ans;
        if(start>end)
        {
            ans.push_back(NULL);
            return  ans;
        }
//         if(start==end)
//         {
//             TreeNode* root=new TreeNode(start);
//             ans.push_back(root);
//             return ans;
//         }
        
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> l= solve(start,i-1);
            vector<TreeNode*>r=solve(i+1,end);
            
            for(int j=0;j<l.size();j++)
            {
                for(int k=0;k<r.size();k++)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=l[j];
                    root->right=r[k];
                    ans.push_back(root);
                }
            }
        }
            return ans; 
        
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
       
        return solve(1, n);
    }
};