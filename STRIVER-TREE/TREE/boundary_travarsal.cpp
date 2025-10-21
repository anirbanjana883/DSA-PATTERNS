Tree Boundary Traversal

class Solution {
    public:
      vector<int>result;
      bool isLeaf(Node *root){
          if(!root->left && !root->right){
              return true;
          }
          return false;
      }
      void addLeftBoundary(Node *root){
          Node *curr=root->left;
          while(curr){
              if(!isLeaf(curr)) result.push_back(curr->data);
              if(curr->left) curr=curr->left;
              // means curr left does no texixts then
              // go to curr right
              else curr=curr->right;
          }
      }
      void addLeafNode(Node *root){ //inorder travarsal
          if(isLeaf(root)){
              result.push_back(root->data);
              return ;
          }
          if(root->left) addLeafNode(root->left);
          if(root->right) addLeafNode(root->right);
      }
      void addRightBoundary(Node *root){
          Node *curr=root->right;
          vector<int>temp;
          while(curr){
              if(!isLeaf(curr)) temp.push_back(curr->data);
              if(curr->right) curr=curr->right;
              // means curr left does no texixts then
              // go to curr right
              else curr=curr->left;
          }
          // for the shake of answer we 
          // have to put element from backword 
          for(int i=temp.size()-1;i>=0;i--){
              result.push_back(temp[i]);
          }
      }
      vector<int> boundaryTraversal(Node *root) {
          // code here
          if(!root) return result;
          // first take root
          if(!isLeaf(root)) result.push_back(root->data);
          addLeftBoundary(root);
          addLeafNode(root);
          addRightBoundary(root);
          return result;
      }
  };