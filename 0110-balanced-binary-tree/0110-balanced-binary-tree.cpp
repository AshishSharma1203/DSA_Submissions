/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
       	// Naive approach  
       	// at each node call for height fn and check the condition for height balanced

       	//     int height(TreeNode *root)
       	//     {
       	//         if (root == NULL) return 0;

       	//         return 1 + max(height(root->left), height(root->right));
       	//     }

       	// bool isBalanced(TreeNode *root)
       	// {

       	//     if (root == NULL)
       	//         return true;

       	//     int lh = height(root->left);
       	//     int rh = height(root->right);

       	//     if ((abs(lh - rh) > 1)) return false;

       	//     return isBalanced(root->left) && isBalanced(root->right);
       	// }

        int height(TreeNode *root)
        {
            if (root == NULL)
                return true;

            int lh = height(root->left);
            int rh = height(root->right);

            if (abs(lh - rh) > 1)
                return -1;

            if (lh == -1 || rh == -1)
                return -1;

            return 1 + max(lh, rh);
        }

    bool isBalanced(TreeNode *root)
    {
        int ans = height(root);
        return ans == -1 ? false : true;
    }
};