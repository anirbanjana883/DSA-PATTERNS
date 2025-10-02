46. Permutations

https://youtu.be/T8hqjK94Fig?si=-r_a_z9Mw9Z49bcQ
watching  explanation needed

approach 1:

class Solution {
public:
    vector<vector<int>>result;
    unordered_set<int>st; // find opreation O(1)
    void solve(vector<int>&temp,vector<int>& nums,int n){
        // base case 
        if(temp.size()==n){
            result.push_back(temp);
            return ;
        }
        // in each permutaion every element come 
        // so for each possibility we have to run loop from 0
        for(int i=0;i<n;i++){
            if(st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(temp,nums,n);

                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // time complexity O(N*N!)
        // space complexity O(2*N+N!)

        int n=nums.size();
        vector<int>temp;
        solve(temp,nums,n);
        return result;
    }
};

approach 2:

class Solution {
public: 
    vector<vector<int>>result;
    void solve(int idx,vector<int>& nums,int n){
        // base case
        if(idx==n){
            result.push_back(nums);
            return;
        }
        // each time the loop will start from idx 
        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            solve(idx+1,nums,n);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // time complexity O(N*N!)
        // space complexity O(N+N!)
        int n=nums.size();
        int idx=0;
        solve(idx,nums,n);
        return result;
    }
};


if string given 

class Solution {
  public:
     void Solve(unordered_set<string>&st,string &s,int idx){
      if(idx>=s.size()){
          st.insert(s);
          return;
      }
      for(int i=idx;i<s.size();i++){
          swap(s[idx],s[i]);
          Solve(st,s,idx+1);
          swap(s[idx],s[i]);
      }
  }
    vector<string> findPermutation(string &s) {
        unordered_set<string>st;
        Solve(st,s,0);
        vector<string>ans;
        for(auto x:st)
        ans.push_back(x);
        return ans;
    }

};