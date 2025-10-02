78. Subsets 

for number [ 1 2 3]
             0 0 0 mask 1
             0 0 1 mask 2
             0 1 0 mask 3
             0 1 1 mask 4
             1 0 0 mask 5
             1 0 1 mask 6
             1 1 0 mask 7
             1 1 1 mask 8


class Solution {
public:
    // Time Complexity: O(2^n * n)
    // space Complexity: O(2^n)
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int no_of_subsets = 1 << n; // 2^n subsets
        vector<vector<int>> ans;
        
        for (int mask = 0; mask < no_of_subsets; mask++) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) { // Check if the i-th bit is set
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};