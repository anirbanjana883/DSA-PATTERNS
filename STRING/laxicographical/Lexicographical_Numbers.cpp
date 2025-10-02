386. Lexicographical Numbers

class Solution {
private:
    // time complexity o(n) each node visited once 
    // space complexity o(no digit in n)= o(logn)[base2]

    void solve(int curr,int limit,vector<int>&result){
        if(curr>limit) return;
        result.push_back(curr);
        for(int i=0;i<=9;i++){
            int next = curr*10 + i;
            if (next > limit) return ;
            solve(next,limit,result);

        }
        return ;
        
    } 
public:
    vector<int> lexicalOrder(int n) {
        vector<int>result;
        for(int i=1;i<=9;i++){
            solve(i,n,result);
        }
        return result;
    }
};