104. Maximum Depth of Binary Tree

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

better understand

class Solution {
public:
int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
    }
};