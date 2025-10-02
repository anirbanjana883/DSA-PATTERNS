3149. Find the Minimum Cost Array Permutation

example  :

Input: nums = [1,0,2]

Output: [0,1,2]

how this is coming ?

                          nums=[1,0,2]
lexicographic permutation perm={0,1,2}
score(perm) = |perm[0] - nums[perm[1]]| + |perm[1] - nums[perm[2]]| + |perm[2] - nums[perm[0]]|
            = |0 - 0| + |1 - 2| + |2 - 1|
            = 2

but if all the perm donot have same ans then we have to take prm with smallest score 



//T.C : O(n!)
//S.C : O(n)
class Solution {
    public:
        int n;
        int minSum = INT_MAX;
        vector<int> result;
    
        void solve(vector<int>& nums, vector<bool>& visited, vector<int>& temp, int sum) {
            if (minSum <= sum)  //If you remove this, you will get TLE. This eliminates many useless calls further
                return; // No point in going further because sum is going higher than minVal
    
            if (temp.size() == n) {
                sum += abs(temp.back() - nums[temp[0]]);
                if (sum < minSum) {
                    minSum = sum;
                    result = temp;   
                }
            }
    
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    temp.push_back(i);
                    solve(nums, visited, temp, sum + abs(temp[temp.size() - 2] - nums[temp[temp.size() - 1]]));
                    temp.pop_back();
                    visited[i] = false;
                }
            }
        }
    
        vector<int> findPermutation(vector<int>& nums) {
            n = nums.size();
            vector<bool> visited(n, false);
            vector<int> temp = {0}; // lexicographically smallest will start from 0
            visited[0] = true; // We have used and hence visited 0
    
            solve(nums, visited, temp, 0);
            return result;
        }
    };
    
    
    