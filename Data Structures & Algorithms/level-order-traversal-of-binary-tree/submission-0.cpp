class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<std::pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            std::pair<TreeNode *, int> n = q.front();
            q.pop();
            if (n.second >= (int)result.size())
                result.push_back({});
            result[n.second].push_back(n.first->val);
            if (n.first->left)
                q.push({n.first->left, n.second + 1});
            if (n.first->right)
                q.push({n.first->right, n.second + 1});
        }
        return result;
    }
};