
199. Binary Tree Right Side View

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> result;
        queue<TreeNode*> q;
        // pusing the root node into the queue
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            TreeNode* node = NULL;
            while (s--) {
                node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            //    the last node in any level is the right side node
            // when he inner while loop ends then the  node will be the last
            // node
            result.push_back(node->val);
        }
        return result;
    }
};