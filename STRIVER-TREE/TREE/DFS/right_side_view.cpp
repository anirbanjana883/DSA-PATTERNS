199. Binary Tree Right Side View

using dfs TRAVARSAL

class Solution {
public:
    void preOrder(TreeNode* root, int level, vector<int>& result) {
        if (!root)
            return;
        // as we going righ side first
        // if the result size is less then level thats mean
        // for that level we need ans
        if (result.size() < level) {
            result.push_back(root->val);
        }
        preOrder(root->right, level+1, result);
        preOrder(root->left, level+1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        preOrder(root, 1, result);
        return result;
    }
};