39. Combination Sum

pattern 1 for solving the combimnation sum type problem:
class Solution {
public:
    // t -  (2^t)*k
    // s -  (k*x)
    vector<vector<int>>result;
    void solve (vector<int>& candidates,int n, int target,vector<int>&temp,int i){
        if(i == n){
            if(target == 0){
                result.push_back(temp);
            }
            return ;
        }

        if(candidates[i] <= target){
            temp.push_back(candidates[i]);
            solve(candidates,n,target - candidates[i],temp,i);
            temp.pop_back();
        }
        solve(candidates,n,target,temp,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>temp;
        solve(candidates,n,target,temp,0);
        return result;
    }
};