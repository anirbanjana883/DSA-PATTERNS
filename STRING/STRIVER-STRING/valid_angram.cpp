242. Valid Anagram

class Solution {
public:
    /*
    Time	O(n log n + m log m)
    Space	O(n + m)
    */
    bool isAnagram(string s, string t) {
        sort(t.begin(),t.end());
        sort(s.begin(),s.end());
        return s==t;
    }
};

class Solution {
public:
    // time O(N)
    // space O(N)
    bool isAnagram(string s, string t) {
        vector<int>hash(26,0);
        for(auto &it : s){
            hash[it-'a']++;
        }
        for(auto &it : t){
            hash[it-'a']--;
        }
        for(auto &it : hash){
            if(it != 0) return false;
        }
        return true;
    }
};