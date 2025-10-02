Longest Substring with At Most K Distinct Characters

it is a premium question on leetcode so try it on coding ninja .. 😁

appproach 1: broute force appproach :

 time complexity : O(n*k) 
 space complexity : O(n) 

#include<bits/stdc++.h>

int kDistinctChars(int k, string &str) {
    int n = str.size();
    unordered_map<char, int> mp;
    int maxLength = INT_MIN;
    for(int i=0;i<n;i++){
        mp.clear();
        for(int j=i;j<n;j++){
            mp[str[j]]++;
            if(mp.size()<=k){
                maxLength=max(maxLength,j-i+1);
            }else{
                break;
            }
        }
    }
    return  maxLength; // Handle cases where no valid substring exists
}

appproach 2: sliding window approach:

time complexity : O(n) 
space complexity : O(k) 

#include<bits/stdc++.h>

int kDistinctChars(int k, string &s) {
    int n = s.size();
    unordered_map<char, int> mp;
    int maxLength = INT_MIN;
    int l=0;
    int r=0;
    while(r<s.size()){
        mp[s[r]]++;
        while(mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0) mp.erase(s[l]);
            l++;
        }
        maxLength=max(maxLength,r-l+1);
        r++;
    }
    return  maxLength; // Handle cases where no valid substring exists
}
