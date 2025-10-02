1358. Number of Substrings Containing All Three Characters

broute force approach :

class Solution {
public:
    // time o (n * n)
    // space o ( 3 )
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0 ; i < n; i++){
            vector<int>hash(3 , 0);
            for(int j = i ; j < n ;j++){
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3) cnt ++ ;
            }
        }
        return cnt;
    }
};

slight optimised approach :

class Solution {
public:
    // time o ( < n * n)
    // space o ( 3 )
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0 ; i < n; i++){
            vector<int>hash(3 , 0);
            for(int j = i ; j < n ;j++){
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3) {
                    // slight optimaisation here 
                    // once we got atleast3 distince char 
                    // all ather ekement away it will be valid 
                    cnt += (n - j);
                    break;
                }
            }
        }
        return cnt;
    }
};

optimla approach :

class Solution {
public:
    // time o ( n)
    // space o ( 3 )
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        // the concept is every char is a ending char of a substring
        vector<int>LastSeen(3,-1);
        for(int i = 0 ; i < n ; i++){
            LastSeen[s[i] - 'a'] = i; // keep tarck where it was seem last time  
            if(LastSeen[0] != -1 && LastSeen[1] != -1 && LastSeen[2] != -1){
                cnt += 1 + min ({LastSeen[0]  ,LastSeen[1] , LastSeen[2]});
            }
        }
        return cnt;
    }
};