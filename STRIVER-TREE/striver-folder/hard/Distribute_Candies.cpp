Distribute Candies


class Solution {
  public:
    // time o(n)
    // space O(1)
    int solve(Node* root , int& moves){
        if(!root) return 0;
        
        int l = solve(root -> left , moves);
        int r = solve(root -> right , moves);
        
        moves += abs(l) + abs(r);
        return (l + r + (root -> data)) - 1;
    }
    int distCandy(Node* root) {
       int moves = 0;
       
       solve(root,moves);
       
       return moves;
    }
};