1028. Recover a Tree From Preorder Traversal

We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child. [imp]

Given the output traversal of this traversal, recover the tree and return its root.


in this problem the we have to assign the node only when the value [no of dash is equals to depth] 
one thoing you must notice yhat you shoi=uld pass i by referance 


class Solution {
    public:

    // t.c O(N)
    // s.c O(N) system stack space
    
        int n;
        TreeNode* solve(string s,int &i,int depth){
            // if cou of bound 
            if(i>=n) return NULL;
    
            // to find dash count 
            int j=i;
            while(j<n && s[j]=='-'){
                j++;
            }
            int dash=j-i;
            if(dash!=depth){
                return NULL;
            }
    
            // move i to j
            i+=dash;
            // forming the integer
            int num=0;
            while(i<n && isdigit(s[i])){
                num=(num*10)+(s[i]-'0'); // to handle multiple digit number
                i++;
            }
    
            TreeNode* root = new TreeNode(num);
            root->left=solve(s,i,depth+1);
            root->right=solve(s,i,depth+1);
    
            return root;
        }
        TreeNode* recoverFromPreorder(string s) {
            n=s.size();
            int i=0;
            int depth=0;
            return solve(s,i,depth);
        }
    };