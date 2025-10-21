124. Binary Tree Maximum Path Sum


class Solution {
public:
    int solve(TreeNode*root,int &maxsum){
        if(!root) return 0;
        int l=solve(root->left,maxsum);
        int r=solve(root->right,maxsum);

        int neeche_ans_mil_gaya=l+r+root->val;

        int koi_ek_achha=max(l,r)+root->val;

        int sirf_root_achha=root->val;
        
        maxsum=max({maxsum,neeche_ans_mil_gaya,koi_ek_achha,sirf_root_achha});
        return max(koi_ek_achha,sirf_root_achha);
    }
    int maxPathSum(TreeNode* root) {
       int  maxsum=INT_MIN;
        solve(root,maxsum);
        return maxsum;

    }
};