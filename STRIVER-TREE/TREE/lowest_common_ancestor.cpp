236. Lowest Common Ancestor of a Binary Tree

Lowest common ancestor of a binary tree is the nearest node which is the ancestor of both the nodes.
see the second example it is imp

let we are travarsing left first
when we first got p then we return p
then go to right when we got q we will return q 

for example 2 
if for any node we gor p from one size and dont get q from another side(got NULL) then p will be the common ancester

case 1: leftn=p and rightn=q then ans = root
case 2: leftn=p and rightn=NULL then ans =p
case 3: leftn=NULL and rightn=q then ans =q


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        // if found p or q then return root(p or q)
        if(root==p || root==q){
            return root;
        }
        // find p or q from left or right
        TreeNode*leftN=lowestCommonAncestor(root->left,p,q);
        TreeNode*rightN=lowestCommonAncestor(root->right,p,q);
        // if both p and q found from both side 
        if(leftN!=NULL && rightN!=NULL){
            return root;
        }
        if(rightN!=NULL){ // leftN is null
            return rightN;
        } 
        // rightN is null
        return leftN;
        
    }
};

foloow up question : 1123. Lowest Common Ancestor of Deepest Leaves