❤️❤️ pattern 1: print all subsequence of a string

void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>&res,int i){
        if(i==nums.size()){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);

        solve(nums,ans,res,i+1); // take (include element)
        res.pop_back();

        solve(nums,ans,res,i+1);// not take (excliude element)
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(nums,ans,res,0);
        return ans;
    }

❤️❤️ pattern 2: print all subsequence whose sum equal to k

void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>&res,int i,int sum){
        if(i==nums.size()){
            if(sum == k){
                ans.push_back(res);
            }
            return
        }
        res.push_back(nums[i]);
        s += nums[i];

        solve(nums,ans,res,i+1,sum); // take (include element)
        s -= nums[i];
        res.pop_back();

        solve(nums,ans,res,i+1,sum);// not take (excliude element)
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        int sum = 0
        solve(nums,ans,res,0,sum);
        return ans;
    }


❤️❤️ pattern 3: print any subsequence whose sum equal to k
>>>>this is the tqechnique to print only one answer

bool solve(vector<int>& nums,vector<int>&ans,vector<int>&res,int i,int sum){
        if(i==nums.size()){ // base case satisfied
            // condition satisfied
            if(sum == k){
                ans.push_back(res);
                return true;
            }
            // condition not satisfied
            else return false
        }
        res.push_back(nums[i]);
        s += nums[i];

        if(solve(nums,ans,res,i+1,sum) == true){
            return true; // avoid future recursn calls
        } 
        s -= nums[i];
        res.pop_back();

        if(solve(nums,ans,res,i+1,sum) == true){
            return true;
        }
        return false; // if no condition satisfied
    }
    vector<int> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<int>res;
        int sum = 0
        solve(nums,ans,res,0,sum);
        return ans;
    }

❤️❤️ pattern 4: count no of subsequence whose sum equal to k

int solve(vector<int>& nums,int count,vector<int>&res,int i,int sum){
        if(i == nums.size()){ // base case satisfied
            // condition satisfied
            if(sum == k){
                return 1;
            }
            // condition not satisfied
            else return 0;
        }
        s += nums[i];

        int l = solve(nums,count,res,i+1,sum); // take (include element)

        s -= nums[i];

        int r = solve(nums,count,res,i+1,sum);
        /*
        for more then 2 recursn calls
        int s =0;
        for(int i = 0; i < nums.size(); i++){
            s += solve(nums,count,res,i+1,sum);
        }
        return s;
        */

        return l + r; // if no condition satisfied
    }
    int subsets(vector<int>& nums) {
        vector<int>res;
        int sum = 0;
        int count = 0;
        solve(nums,count,res,0,sum);
        return count;
    }