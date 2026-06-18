class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {   if (!root) return true;
        int lheight = height(root->left);
        int rheight = height(root->right);
        return abs(lheight - rheight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int lheight = height(root->left);
        int rheight = height(root->right);
        return max(lheight, rheight) + 1;
    }
};