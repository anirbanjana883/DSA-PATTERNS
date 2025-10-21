INORDER  TRAVARSAL

There are three solutions to this problem.

Iterative solution using stack: O(n) time and O(n) space;
Recursive solution: O(n) time and O(n) space (function call stack);
Morris traversal: O(n) time and O(1) space.


Iterative solution using stack

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        while (root || !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root -> val);
            root = root -> right;
        }
        return nodes;
    }
};


Recursive solution


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
private:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
};


Morris traversal

explanation  https://youtu.be/Wq3ibaP4dJY?si=8mb-gyyyIn-zdvwp

note in recursn we can revert back to the previous 
node but in iterative approach we dont have this feature 
to get this feature we need morris travarsal

t.c O(N) 
s.c O(1)  [advantage]

class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            TreeNode* curr = root;
            while (curr) {
                if (!curr->left) { // L,V,R
                    result.push_back(curr->val);
                    curr = curr->right;
                } else {
                    TreeNode* leftChild = curr->left;
                    while (leftChild->right) {
                        leftChild = leftChild->right;
                    }
                    leftChild->right = curr;
                    // now mark NULL the left of current
                    // to prevent revisiting
                    TreeNode* temp = curr;
                    curr = curr->left;
                    temp->left = NULL;
                }
            }
            return result;
        }
    };