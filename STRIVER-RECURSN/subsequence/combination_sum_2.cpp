40. Combination Sum II

Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

pattern 2 for solving the combimnation sum type problem:

in recursn question whever you get duyplicate - try to think of sorting the array first

class Solution {
public:
    // t o(2^n * k) k - putting element into ans
    // s o(k*x)
    vector<vector<int>>answer;
    void solve (vector<int>& candidates,vector<int>&temp,int target,int ind){
        if(target < 0) return ;
        if(target == 0){
            answer.push_back(temp);
            return ;
        }

        for(int i = ind ; i < candidates.size() ; i++){
            // check for same item to avoid duplication

            //  for first time we will be pick 
            // but for second time onword we will not pick same item
            if ( i > ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

            temp.push_back(candidates[i]); // do
            solve(candidates, temp, target - candidates[i], i+1);
            temp.pop_back(); // undo 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sorting to get all same element together 
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        solve(candidates, temp, target, 0);
        return answer;
    }
};