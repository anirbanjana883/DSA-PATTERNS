105. Construct Binary Tree from Preorder and Inorder Traversal

preorder = [3,9,20,15,7] root left right
inorder =  [9,3,15,20,7] left root right
            3
           / \
           9  20 15   7 
           
            3
           / \
          9  20
             /  \
            15   7  
> in preorder we will take first element as root 
> then we will found that element in inorder [let it index is i]
> then we will find the left and right child of that element in inorder
                left child = start to i-1   inorder[ start  end]
                right child = i+1 to end

class Solution {
    public:
        TreeNode*solve(vector<int>& preorder,vector<int>& inorder,int start,int end,int &idx){
            if(start>end) return NULL;

            // finding the root value in the preorder array
            int rootValue=preorder[idx];
            // i will be finding where the root value stand in the inorder       
            int i;
            for(i=start;i<=end;i++){
                if(inorder[i]==rootValue){
                    break; // now we found the index of rootvalue in the inorder
                }
            }
            idx++;
            // building the root
            TreeNode* root=new TreeNode(rootValue);
            // call for root->left
            root->left=solve(preorder,inorder,start,i-1,idx);
            // call for root->right
            root->right=solve(preorder,inorder,i+1,end,idx);

            return root;
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int n=preorder.size();
            int idx=0;
            //            preorder   start  end
            return solve(preorder,inorder,0,n-1,idx);
        }
};