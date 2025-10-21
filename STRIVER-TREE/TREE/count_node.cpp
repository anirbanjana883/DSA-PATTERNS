 time complexity  o(n)

 class Solution {
public:
    void count(TreeNode* root,int &cnt){
        if(!root) return;
        cnt++;
         count(root->left,cnt);
         count(root->right,cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt=0;
        count(root,cnt);
        return cnt;

    }
};

******important******
 time complexity  o(log n)^2   < o(n)
  
 for a perfect binary tree number of node =((2^H)-1)  [H height/level of binary tree]

 class Solution {
public:
     int find_left_height(TreeNode* root){
        TreeNode* temp=root;
        int lh=0;
        while(temp){
            temp=temp->right;
            lh++;
        }
        return lh;
     }
     int find_right_height(TreeNode* root){
        TreeNode* temp=root;
        int rh=0;
        while(temp){
            temp=temp->left;
            rh++;
        }
        return rh;
     }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=find_left_height(root);
        int rh=find_right_height(root);
        // if lh==rh perfect binary tree
        if(lh==rh) return (pow(2,lh)-1);
        //  if not pbt then left mein and right mein alag alg jao 
        // and root node ke sath sabko add kardo
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};