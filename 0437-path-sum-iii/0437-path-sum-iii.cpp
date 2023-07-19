/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

       	//     Approach 1: TC o(n^2);

       	//     int solve(TreeNode* root,long int sum,int target)
       	//     {

       	//         if(root==NULL)
       	//             return 0;

       	//         return(sum+root->val==target)+ solve(root->left,sum+root->val,target)+ solve(root->right,sum+root->val,target)
       	// ;        
       	//     }

       	//     int pathSum(TreeNode* root, int targetSum) {
       	//         if(root==NULL)
       	//             return 0;

       	//         return solve(root,0,targetSum)+ pathSum(root->left,targetSum)+ pathSum(root->right,targetSum);
       	//     }

        void solve(TreeNode *curr, long long int sum, int target, int &ans, unordered_map<long, int> &m)
        {

            if (curr == NULL)
                return;

          long long   int currsum = sum + curr->val;
            if (currsum == target)
                ans++;
            if (m.find(currsum - target) != m.end())
            {
                ans += m[currsum - target];
            }
            m[currsum]++;
            solve(curr->left, currsum, target, ans, m);
            solve(curr->right, currsum, target, ans, m);

            m[currsum]--;
        }

    int pathSum(TreeNode *root, int targetSum)
    {

        int ans = 0;
        unordered_map<long, int> mp;
       	// mp[0]++;
        solve(root, 0, targetSum, ans, mp);

        return ans;
    }
};