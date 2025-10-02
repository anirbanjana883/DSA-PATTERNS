39. Combination Sum

approach 1: without for loop

class Solution {
    public:
        int Sum(vector<int>& arr) {
            int sum = 0;
            for(int i = 0; i<arr.size(); i++)
                sum += arr[i];
            return sum;
        }
        void combination(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
            if(Sum(curr) > target || idx >= candidates.size())
                return;
            if(Sum(curr) == target) {
                result.push_back(curr);
                return;
            }
            curr.push_back(candidates[idx]);
            // since we can take same elemnt multiple time 
            // during adding we are not incrementing the index
            combination(candidates, target, curr, result, idx); 
            curr.pop_back();
            combination(candidates, target, curr, result, idx+1);
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> result;
            vector<int> curr;
            
            combination(candidates, target, curr, result, 0);
            return result;
        }
    };

    approach 2: with for loop 

    class Solution {
        public:
            void combination(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
                if(target < 0)
                    return;
                if(target == 0) {
                    result.push_back(curr);
                    return;
                }
                
                for(int i = idx; i < candidates.size(); i++) {
                    curr.push_back(candidates[i]);
                    combination(candidates, target-candidates[i], curr, result, i);
                    curr.pop_back();
                }
            }
            vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
                vector<vector<int>> result;
                vector<int> curr;
                
                combination(candidates, target, curr, result, 0);
                return result;
            }
        };