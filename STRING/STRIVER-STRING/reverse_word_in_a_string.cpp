151. Reverse Words in a String

class Solution {
public:
    // time o(n)
    // space o(n)
    string reverseWords(string s) {
        int n = s.size();
        vector<string>vec;
        string tmp = "";
        for(auto &it : s){
            if(it == ' ') {
                if(!tmp.empty()){
                    vec.push_back(tmp);
                    tmp = "";
                }
            }else{
                tmp += it;
            }
        }
        // last char must be pushed 
        if(!tmp.empty()) vec.push_back(tmp);
        reverse(vec.begin(),vec.end());
        string res = "";
        for(auto &it : vec){
            res += it;
            res += " ";
        }
        res.pop_back(); // to avoid the last space 
        return res;
    }
};

using cpp stl 

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        string result = "";
        while(ss >> token){
            result = token + " " + result;
        }
        // delete last space 
        result.pop_back();
        return result;
    }
};



class Solution {
public:
    // time o(n)
    // space o(1)
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin() , s.end());
        int l = 0;
        int r = 0;
        int i = 0;
        while(i < n){
            // till i see char it give char to r and move
            while ( i < n && s[i] != ' '){
                s[r++] = s[i++];
            }
            if(l < r){
                reverse ( s.begin() + l , s.begin() + r);
                s[r] = ' ';
                r++;
                l=r;
            }
            i++;
        }
        // remove last space
        s = s.substr(0,r-1);
        return s; 
    }
};