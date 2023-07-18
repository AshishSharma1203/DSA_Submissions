/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        bool solve(TreeNode *curr, int sum, int target)
        {

            if (curr == NULL)
            {
                return false;
            }
            if (curr->left == NULL && curr->right == NULL)
                return sum+curr->val == target;

            return solve(curr->left, sum + curr->val, target) || solve(curr->right, sum + curr->val, target);
        }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        return solve(root, sum, targetSum);
    }
};