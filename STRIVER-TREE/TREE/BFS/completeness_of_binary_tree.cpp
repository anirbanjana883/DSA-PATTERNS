958. Check Completeness of a Binary Tree

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

solving using [BFS]

approach in any lavel null should not be present
if present it should be at last if the null is in middle then it is not complete B.Tree


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool isNullSeenBefore = false; // track of null seen before or not
        while (!q.empty()) {
            // typical bfs
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) {
                isNullSeenBefore = true; // if val of current node is null
            } else {                     // if val of current node is not null
                if (isNullSeenBefore == true) {   // cheak if null seen before or not
                    return false; // if null seen before then i is not complete BT
                }
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
};