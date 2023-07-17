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

TreeNode* find(TreeNode* curr) 
{
   if(curr->left==NULL)
       return curr;
    return find(curr->left);
}

TreeNode* solve(TreeNode* curr) {
    if (curr == NULL) {
        return NULL;
    }

    if (curr->left == NULL) {
        return curr->right;
    } else if (curr->right == NULL) {
        return curr->left;
    }

    TreeNode* curr_right = curr->right,*curr_left=curr->left;
    TreeNode* pos = find(curr_right);
    pos->left = curr_left;
    // pos->right = curr->right;
    delete curr;
    return curr_right;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (root->val == key) {
        return solve(root);
    }

    TreeNode* curr_root = root;
    while (root != NULL) {
        if (root->val > key) {
            if (root->left != NULL && root->left->val == key) {
                root->left = solve(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if (root->right != NULL && root->right->val == key) {
                root->right = solve(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }

    return curr_root;
}

};