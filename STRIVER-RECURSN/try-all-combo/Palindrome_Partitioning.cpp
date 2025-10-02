131. Palindrome Partitioning

class Solution {
public:
    // t.c O(n*(2^n))
    // s.c O(n)
    int n;
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void back_track(string s,int idx,vector<string>&curr,vector<vector<string>>&res){
        // base case
        if(idx==n){ // why n 
            res.push_back(curr);
            return ;
        }

        for(int i=idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                // explore
                curr.push_back(s.substr(idx,i-idx+1));
                back_track(s,i+1,curr,res);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        //  why backtracking 
        //-> return all possible .........
        // do partition from idx to i
        n=s.size();
        vector<vector<string>>res;
        vector<string>curr;
        back_track(s,0,curr,res);
        return res;
    }
};