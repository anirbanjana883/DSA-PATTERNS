46. Permutations

approach 1 : 
uing map : 

class Solution {
public:
    // time n! * n
    // space N*K + N for map and result

    vector<vector<int>>result;
    vector<int>temp;
    unordered_map<int , bool> mp;
    void solve ( vector<int>& nums ,int n){
        if(temp.size() == n) {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < n ;i++){
            if(!mp[i]){ // not visited
                // mark as visited
                mp[i] = true; // tske
                temp.push_back(nums[i]);
                solve(nums,n);
                mp[i] = false; // not take
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        solve(nums,n);
        return result;
    }
};

approach 2 :

class Solution {
public:
    // time n! * n
    // space  N for result

    vector<vector<int>>result;
    void solve ( vector<int>& nums ,int n,int idx){
        
        if ( idx == n){
            result.push_back(nums);
            return ;
        }
        for(int i = idx; i < n ;i++){
            swap(nums[idx],nums[i]);
            solve(nums,n,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        solve(nums,n,0);
        return result;
    }
};