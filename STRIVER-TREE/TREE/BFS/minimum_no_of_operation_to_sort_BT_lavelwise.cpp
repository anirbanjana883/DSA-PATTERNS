2471. Minimum Number of Operations to Sort a Binary Tree by Level


class Solution {
public:
    void findSwap(vector<int>& vec, int& NoOfSwap) { // this can be a seperate question
        // we will find the correct index first of each elemnt 
        vector<int>sortedVec=vec;
        sort(begin(sortedVec),end(sortedVec));

        unordered_map<int,int>mp; // nums[i]->i
        for(int i=0;i<vec.size();i++){
            mp[vec[i]]=i;
        }
        // placing the correct eleemnt in correct position
        for(int i=0;i<vec.size();i++){
            // if element is in correct position then do nothing
            if(vec[i]==sortedVec[i]) continue; // no swap 
            // finding which elemnt is in the current index
            // in sorted array
            int currIdx=mp[sortedVec[i]];
            // updatuing the idx
            mp[vec[i]]=currIdx;
            mp[vec[currIdx]]=i;
            // swap
            swap(vec[currIdx],vec[i]);
            NoOfSwap++;
        }
    }
    int minimumOperations(TreeNode* root) {
        // time complaexity O(N+Wlog(N))
        // here the catch is finding minimum
        // no of aswap needed for sorting the array
        queue<TreeNode*> q;
        int NoOfSwap = 0;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> vec(n);
            while (n--) {
                TreeNode* top = q.front();
                q.pop();
                vec.push_back(top->val);
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
            findSwap(vec, NoOfSwap);
        }
        return NoOfSwap;
    }
};