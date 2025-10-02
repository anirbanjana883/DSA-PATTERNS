1781. Sum of Beauty of All Substrings

approach : broute force

class Solution {
public:
    //  t o(n^3)
    int find(string &s,int i,int j){
        unordered_map<int,int>mp;
        for(int ind = i ;ind <= j ;ind++){
            mp[s[ind]]++;
        }
        int mx = INT_MIN;
        int mn = INT_MAX;

        for(auto &it : mp){
            if(it.second > mx) mx = it.second;
            if(it.second < mn) mn = it.second; 
        }
        return mx - mn;
    }
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int beauty = find(s,i,j);
                sum += beauty;
            }
        }
        return sum;
    }
};

class Solution {
public:
    int beautySum(string s) {
        // time o(n*n*26)
        int n = s.size();
        unordered_map<char,int>mp;
        int sum = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int mx = INT_MIN;
                int mn = INT_MAX;
                for(auto &it : mp){ // at worst acse there will be 26 char
                    mx=max(mx,it.second);
                    mn=min(mn,it.second);
                }
                sum += mx-mn;
            }
            mp.clear();
        }
        return sum ;
    }
};