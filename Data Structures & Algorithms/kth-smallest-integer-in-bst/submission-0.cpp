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

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int numVisited = 0;
        int store = -1;
        inOrder(root, numVisited, store, k);
        return store;
    }
    void inOrder(TreeNode *root, int &visited, int &store, int k)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            visited++;
            if (visited == k)
                store = root->val;
            return;
        }

        inOrder(root->left, visited, store, k);
        visited++;
        if (visited == k)
            store = root->val;
        inOrder(root->right, visited, store, k);
    }
};
