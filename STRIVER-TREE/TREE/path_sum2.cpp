113. Path Sum II 


class Solution {
public:
    vector<vector<int>>result;
    void findCorrectPath(TreeNode* root, int targetSum,int sum,vector<int>temp){
        if(!root) return ;
        sum+=root->val;
        temp.push_back(root->val);
        // if we reacj to the leaf node 
        if(!root->left && !root->right){
            // cheaking is sum is =targetsum
            if(sum==targetSum){
                result.push_back(temp);
            }
            return ;
        }
        
        findCorrectPath(root->left,targetSum,sum,temp);
        findCorrectPath(root->right,targetSum,sum,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // we have to return all the path 
        // here backtracking also needed
        int sum=0;
        vector<int>temp;
        findCorrectPath(root,targetSum,sum,temp);
        return result;
    }
};