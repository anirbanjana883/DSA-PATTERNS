216. Combination Sum III

class Solution {
public:
    // time o ( 2 ^ 9)
    // space o( k * x) k - avg size of subset 
    vector<vector<int>>result;
    vector<int>temp;
    void solve(int no_of_element, int target, int i){
        if(no_of_element == 0 && target == 0){
            result.push_back(temp);
            return ;
        }
        if(no_of_element < 0 || target < 0  || i > 9) return;
        temp.push_back(i);
        solve(no_of_element - 1,target - i,i + 1); // take
        temp.pop_back();
        solve(no_of_element,target,i + 1); // not take
    }
    vector<vector<int>> combinationSum3(int no_of_element, int target) {
        solve(no_of_element,target,1);
        return result;
    }
};