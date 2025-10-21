1123. Lowest Common Ancestor of Deepest Leaves

approach 1::

time complexity: O(2n)
space complexity: O(maxDepth)

class Solution {
    public:
        unordered_map<TreeNode*, int> depthMap; // Map to store depth of each node
        int maxDepth = 0;
    
        // Function to calculate depth of each node
        void findDepth(TreeNode* root, int depth) { // o(n)
            if (!root) return;
    
            depthMap[root] = depth;
            maxDepth = max(maxDepth, depth);
    
            findDepth(root->left, depth + 1);
            findDepth(root->right, depth + 1);
        }
    
        // Function to find the LCA of the deepest leaves
        TreeNode* findLCA(TreeNode* root) { // o(n)
            if (!root) return nullptr;
    
            // If the current node's depth is the maximum, it is a candidate for LCA
            if (depthMap[root] == maxDepth) return root;
    
            TreeNode* left = findLCA(root->left);
            TreeNode* right = findLCA(root->right);
    
            // If both left and right are non-null, the current node is the LCA
            if (left && right) return root;
    
            // Return non-null child
            return left ? left : right;
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            if (!root) return nullptr;
    
            // First, calculate the depth of each node
            findDepth(root, 0);
    
            // Then, find the LCA of nodes with the maximum depth
            return findLCA(root);
        }
    };
    

appproach 2:: one pass

time complexity: O(n)
space complexity: O(n)

class Solution {
    public:
        pair<int, TreeNode*> solve(TreeNode* root) {  // o(n) single pass
            // Base case: If the node is null, return depth 0 and NULL node
            if (root == NULL) {
                return {0, NULL};
            }
    
            // Recursive calls for left and right children
            auto left = solve(root->left);
            auto right = solve(root->right);
    
            // Compare depths of left and right subtrees
            if (left.first == right.first) {
                return {left.first + 1, root};  // Equal depths, return current node
            } else if (left.first > right.first) {
                return {left.first + 1, left.second};  // Left subtree is deeper
            } else {
                return {right.first + 1, right.second}; // Right subtree is deeper
            }
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            // Get the second value (node) from the pair returned by `solve`
            return solve(root).second;
        }
    };
    

exact same question:
865. Smallest Subtree with all the Deepest Nodes
