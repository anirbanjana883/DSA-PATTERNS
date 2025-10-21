543. Diameter of Binary Tree

class Solution {
public:
    int findDiameter(TreeNode* root,int &maxi){
        if(!root) return 0;
        int leftHeight=findDiameter(root->left,maxi);
        int rightHeight=findDiameter(root->right,maxi);
        // each node has two work eaither 
        //  it may be the ans
        maxi=max(maxi,leftHeight+rightHeight);
        // or we acn get more better ans upeer side
        // for that it has to find wheather it is
        // getting greater diameter from right or left
        return max(leftHeight,rightHeight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MIN;
        findDiameter(root,ans);
        return ans;
    }
};