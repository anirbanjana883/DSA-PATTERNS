1048. Longest String Chain

how it is similar to print LIS ?
remember the if(nums[i]>nums[prev] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
in every element nextto prev has just one char differnec 
{ nums[i]>nums[prev] } if we change this to { compare(nums[i],nums[j]) }  boom  💥

time complexity o(n^2+l)+o(n)
class Solution {
public: 
    bool checkIfPossible(string &s1,string &s2){
        // notice that s1 will be greater then s2;
        // the length of s1 should be +1 then s2
        if(s1.length()!=s2.length()+1) return false;
        int first=0;
        int second=0;
        while(first<s1.length()){
            if(s1[first]==s2[second] && second<s2.length()){
                first++,second++;
            }else{
                first++;
            }
        }
        // if both first and second reached end simultaniously 
        if(first==s1.length() && second==s2.length()) return true;
        return false;
    }
    static bool comp(string &s1, string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1); // Each word is a chain of length at least 1
        int maxi = 1;

        sort(words.begin(), words.end(), comp);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkIfPossible(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};