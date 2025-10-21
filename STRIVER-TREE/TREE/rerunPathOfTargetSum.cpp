you have to return a path thatb can give a target sum


class Solution {
public:
    void calculate(TreeNode* root,int targetSum,int sum, vector<int>temp,vector<vector<int>>&fres){
        if(!root) return;
        sum+=root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(sum==targetSum)
            fres.push_back(temp);
        }
        calculate(root->left,targetSum,sum,temp,fres);
         calculate(root->right,targetSum,sum,temp,fres);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        vector<vector<int>>fres;
        calculate(root,targetSum,0,temp,fres);
        return fres;
    }