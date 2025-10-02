2305. Fair Distribution of Cookies

first do distribution
let example  [8,15,10]
distribution [[18,15],[8,25],[33,0],[23,10],[25,8],[15,18],[10,23],[0,43]]
unfairness   18,25,33,23,25,18,23,43
answer  18
unfairness->maximum of all distribution 
answer-> minimum of all unfairness


class Solution {
public:
    int result=INT_MAX;
    int n; 
    void solve(int idx,vector<int>& cookies,vector<int>& children,int k){
        if(idx>=n){
            int unfairness=*max_element(begin(children),end(children));
            result=min(result,unfairness);
            return;
        }
        // /for each child there is a chance of taking one cookie or not
        int cookie=cookies[idx];
        for(int i=0;i<k;i++){
            children[i]+=cookie; // cookie given
            solve(idx+1,cookies,children,k); //explore
            children[i]-=cookie; // cookie taken back
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        // time complexity O(k^n)
        // space complexity O(n)
        n=cookies.size();
        vector<int>children(k,0);
        solve(0,cookies,children,k);
        return result;
    }
};
