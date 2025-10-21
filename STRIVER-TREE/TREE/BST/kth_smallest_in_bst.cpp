230. Kth Smallest Element in a BST

approach 1: broute force 

t.c O(N+Nlog(N))

class Solution {
    public:
        vector<int>vec;
        void solve(TreeNode* root){
            if(!root) return;
            vec.push_back(root->val);
            solve(root->left);
            solve(root->right);
        }
        int kthSmallest(TreeNode* root, int k) {
            solve(root);
            sort(vec.begin(),vec.end());
            return vec[k-1];
        }
    };


approach 2 optimised approach :
  inorder travarsal of bst is in sorted order so we can directly return the kth element from the inorder travarsal of the tree
  t.c O(N)
  s.c O(N)
  class Solution {
    public:
        vector<int> vec;
        void solve(TreeNode* root) {
            if (!root)
                return;
            solve(root->left);
            vec.push_back(root->val);
            solve(root->right);
        }
        int kthSmallest(TreeNode* root, int k) {
            solve(root);
            return vec[k - 1];
        }
    };

approach 3: optimal approach 

t.c O(N)
s.c O(1)  ignoring the recursn stack memory 

    morris travarsal

    during travarsal if we count k then hwne we reach k we can return ans 

    recursive travarsal t.c O(N) s.c O(N)
    iterative  travarsal t.c O(N) s.c O(N)
    morris travarsal t.c O(N) s.c O(1) so we will use morris travarsal 

    class Solution {
        public:
            vector<int> inorderTraversal(TreeNode* root) {
                vector<int> result;
                TreeNode* curr = root;
                while (curr) {
                    if (!curr->left) { // L,V,R
                        result.push_back(curr->val);
                        curr = curr->right;
                    } else {
                        TreeNode* leftChild = curr->left;
                        while (leftChild->right) {
                            leftChild = leftChild->right;
                        }
                        leftChild->right = curr;
                        // now mark NULL the left of current
                        // to prevent revisiting
                        TreeNode* temp = curr;
                        curr = curr->left;
                        temp->left = NULL;
                    }
                }
                return result;
            }
        };