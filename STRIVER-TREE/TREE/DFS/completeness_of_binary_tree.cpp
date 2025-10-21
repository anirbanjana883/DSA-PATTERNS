958. Check Completeness of a Binary Tree

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

solveing using [DFS]

binary tree can be represented as an array where indexing is done as following

            *[i]=1
           / \
   2=[2*i]*   *[(2*i)+1]=3
             /  \
            *    *  

            3
           / \
          9  20
             /  \
            15   7       array idx 1  2  3   4   5  6  7
                                   3  9  20         15 7  not a complete BT
   so  index > node_count ==> not a complete binary tree
       index <= node_count ==>  a complete binary tree
    
    for a complete binary tree there should not be any gap in the array 

class Solution {
    public:
        bool DFS(TreeNode*root,int idx,int noOfNode){
            // if no node present then it is a complete BT
            if(root==NULL) return true;
            // if index>no of node then it is not complete BT
            if(idx>noOfNode){
                return false;
            }
            return DFS(root->left,2*idx,noOfNode) && DFS(root->right,2*idx+1,noOfNode);
        }
        int countNode(TreeNode*root){
            if(root==NULL) return 0;
            return 1+countNode(root->left)+countNode(root->right);
        }
        bool isCompleteTree(TreeNode* root) {
            // first we have to find no of node
            int noOfNode=countNode(root);
            int i=1;
            return DFS(root,i,noOfNode);
        }
};