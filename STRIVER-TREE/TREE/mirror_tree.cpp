MIRROR TREE GFG

approach 1:

class Solution {
  public:
    Node* solve(Node* root){
        if(!root) return NULL;
        Node* mirrored_Left=solve(root->left);
        Node* mirrored_right=solve(root->right);
        
        root->left=mirrored_right;
        root->right=mirrored_Left;
        
        return root;
    }
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here+
        solve(node);
    }
};


approach 2:

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        if(!root) return ;
        
        swap(root->left,root->right);
        
        mirror(root->left);
        mirror(root->right);
    }
};
