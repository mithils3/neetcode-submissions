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
        if (!root || visited >= k)   // stop if done or nothing to do
            return;

        inOrder(root->left, visited, store, k);

        if (visited >= k)            // answer already found in left subtree
            return;

        visited++;
        if (visited == k)
        {
            store = root->val;
            return;                  // don't descend right; we're done
        }

        inOrder(root->right, visited, store, k);
    }
};