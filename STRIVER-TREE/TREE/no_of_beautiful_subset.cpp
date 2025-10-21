2597. The Number of Beautiful Subsets

class Solution {
    public:
        int result = 0;
        unordered_map<int, int> mp;
        void solve(vector<int>& nums, int k, int n, int idx) {
            // base case
            if (idx == n) {
                result++;
                return;
            }
            solve(nums, k, n, idx + 1);
            if (!mp[nums[idx] - k] && !mp[nums[idx] + k]){            
                mp[nums[idx]]++;
                solve(nums, k, n, idx + 1);
                mp[nums[idx]]--;
            }
        }
        int beautifulSubsets(vector<int>& nums, int k) {
            int n = nums.size();
            solve(nums, k, n, 0);
            return result-1;
        }
    };