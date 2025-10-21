98. Validate Binary Search Tree

class Solution {
    public:
        bool solve(TreeNode* root,long long l,long long r){
            if(!root) return true;
            if(root->val<r && root->val>l){
                return solve(root->left,l,root->val) && solve(root->right,root->val,r); 
            }
            return false;
        }
        bool isValidBST(TreeNode* root) {
            long long mn=LLONG_MIN;
            long long mx=LLONG_MAX;
            return solve(root,mn,mx);
        }
    };