112. Path Sum 

class Solution {
public:
    bool ifPossible(TreeNode* root, int targetSum ,int sum ){
        if(!root) return false;
        // each time we are calculating the sum
        sum+=root->val;
        // as soon as we reach the leaf node
        // we will cheak if this path can give target sum or not
        if(!root->left && !root ->right){
            if(sum == targetSum) {
                return true;
            }
            return false;
        }
        // we will check from both left and right
        // if we get true from anyside then we return true
        bool leftSide=ifPossible(root->left,targetSum,sum);
        bool rightSide=ifPossible(root->right,targetSum,sum);
        return leftSide || rightSide;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;

        bool result=ifPossible(root,targetSum,sum);
        return result;
    }
};