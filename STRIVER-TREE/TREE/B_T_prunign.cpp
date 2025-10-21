814. Binary Tree Pruning 


approach 1 :

time complexity O(N^2)

class Solution {
public:
    bool isOnePresent(TreeNode* root){
        // means we have reached to the last node still we 
        // dont find any 1
        if(!root) return false;
        // if we found 1 
        if(root->val == 1) return true;
        // if we got 1 from eaither left or right we will return true
        return isOnePresent(root->left) || isOnePresent(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        // ons atanding each node we check if its left or right 
        // has atleast one 1 if yes then 
        // next recursive call or return NULL
        
        // time complexity O(N^2)

        if(!root){
            return NULL;
        }
        // if we get no 1 from root left
        if(!isOnePresent(root->left)) root->left=NULL;
        // if we get no 1 from root right
        if(!isOnePresent(root->right)) root->right=NULL;

        // if we got any 1 from child the check for them again
        pruneTree(root->left);
        pruneTree(root->right);
        // edge case 
        // if onlt one node presetn and it is zero
        if(!root->left && !root->right && root->val==0){
            return NULL;
        }
        return root;
    }
};

approach 2: 

time complexity O(N^2)

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        // time complexity O(N)
        // if any leaf node has value zero then delete it

        // at first recah te leaf node 
        if(!root) return NULL;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        // cheeck if this is a leaf node with value zero 
        if(root->left== NULL && root->right== NULL && root->val== 0){
            return NULL;
        }
        return root;
    }
};