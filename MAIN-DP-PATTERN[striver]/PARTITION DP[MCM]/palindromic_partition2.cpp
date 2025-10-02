132. Palindrome Partitioning II


approach 1:recursn 
t.c -  exponential
s.c - o(c)

class Solution {
public:
// FRONT PARTITION PROBLEM
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int findCut(int i,int n,string &s,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int minCut=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cuts=1+findCut(j+1,n,s,dp);
                minCut=min(minCut,cuts);
            }
        }
        return minCut;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return findCut(0,n,s,dp)-1; //since it is adding a cut at last also
    }
};

approach 2:memoization 
t.c - o(n^3) 
s.c - o(n)+o(n)

class Solution {
public:
// FRONT PARTITION PROBLEM
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int findCut(int i,int n,string &s,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int minCut=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cuts=1+findCut(j+1,n,s,dp);
                minCut=min(minCut,cuts);
            }
        }
        return dp[i]=minCut;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return findCut(0,n,s,dp)-1; //since it is adding a cut at last also
    }
};

approach 2:tabulation 
t.c - o(n^3) 
s.c - o(n)

class Solution {
public:
// FRONT PARTITION PROBLEM
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
 
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int minCut=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    int cuts=1+dp[j+1];
                    minCut=min(minCut,cuts);
                }
            }   
            dp[i]=minCut;
        }
        return dp[0]-1; //since it is adding a cut at last also
    }
};