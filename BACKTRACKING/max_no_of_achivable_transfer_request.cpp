1601. Maximum Number of Achievable Transfer Requests  [hard]

class Solution {
public: 
    // t.c O(N*(2^N))
    // t.c O(N)
    int result=INT_MIN;
    void solve(int idx,int count,vector<int>&resultant,vector<vector<int>>& requests) {
        // base case
        if(idx>=requests.size()){
            bool allZero=true;
            for(int &x:resultant){
                if(x!=0){
                    allZero=false;
                    break;
                }
            }
            // means this path is a valid path
            if(allZero==true){
                result=max(result,count);
            }
            return;
        }
            int from=requests[idx][0];
            int to=requests[idx][1];
            // take
            resultant[from]--;
            resultant[to]++;
            // /explore
            solve(idx+1,count+1,resultant,requests);
            // revert back 
            resultant[from]++;
            resultant[to]--;
            // explore
            solve(idx+1,count,resultant,requests);
    }       
    int maximumRequests(int n, vector<vector<int>>& requests) {
        // why back tarcking 
        // for each request we have choice 
        // that we will process it or not

        int count=0;
        vector<int>resultant(n,0);
        solve(0,count,resultant,requests);
        return result;
    }
};