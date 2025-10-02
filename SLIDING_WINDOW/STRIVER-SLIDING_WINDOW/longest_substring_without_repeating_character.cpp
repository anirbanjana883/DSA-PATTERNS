3. Longest Substring Without Repeating Characters 

we does have to apply the concept of hashing to solve the question 
broute force approach ->

class Solution {
public:
// time complexity O(n^2)
//  space complexity O(26)
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int len=0;
        for(int i=0;i<n;i++){
            // we are hashing all the character into the hashing 
            // vector to cheack repeating 
            vector<int>hash(26,0);
            for(int j=i;j<n;j++){
                // if we seen the repeting char then we are
                // discarding the character 
                
                if(hash[s[j]-'a']==1) break;
                // calculating the max length 
                len=max(len,(j-i+1));
                // hashinng the current character 
                hash[s[j]-'a']=1;
            }
        }
        return len;
    }
};

optimised approach ->  striver explanation love ❤️ 

time complexity O(n)
space complexity O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; // character -> index
        int n = s.size();
        if (n == 1)
            return 1;

        int l = 0;
        int maxLength = 0;

        for (int r = 0; r < n; ++r) {
            // we are checking if we have  seen the current eleemnt before
            // we also checking if the current elemnt is in range of the 
            // current substring or not 
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }
            // updating the current char index 
            mp[s[r]] = r; // storing where we have seen the character 
            // updating the max length 
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
