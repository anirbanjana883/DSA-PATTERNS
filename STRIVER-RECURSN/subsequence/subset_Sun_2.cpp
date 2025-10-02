90. Subsets II


same pattern as combination sum 2
approach 1 : uaing recursion and set to avoid duplicates
class Solution {
public:
    // time o( 2^n * nlogn) 
    // space o(2^n)
    int n;
    set<vector<int>>result;
    vector<int>temp;
    void solve(vector<int>& nums ,int i){
        if( i == n){
            result.insert(temp);
            return ;
        }
        temp.push_back(nums[i]);
        solve(nums , i + 1);
        temp.pop_back();
        solve(nums , i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        // to avoid duplicates, we can sort the array first
        sort(nums.begin() , nums.end());
        solve(nums , 0);
        return vector<vector<int>>(result.begin(),result.end()); // it will take extra time to convert set to vector
    }
};

approach 2 : using recursion and backtracking

class Solution {
public:
    // time 2^n * n
    // space 2^n * k k - av len of any subste 
    int n;
    vector<vector<int>>result;
    vector<int>temp;
    void solve(vector<int>& nums ,int ind){
        result.push_back(temp);
        for(int i = ind ; i < n ;i++){
            //  for first time we will be pick 
            // but for second time onword we will not pick same item
            if( i > ind && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums , i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin() , nums.end()); // avoid duplication
        solve(nums , 0);
        return result;
    }
};