2953. Count Complete Substrings


class Solution {
public:
    // Time Complexity: O(26 * n)
    // Time Complexity: O(26 * n)
    int solve( int start ,int end ,string &word , int k){
        int result = 0;
        // 1 unique char ,2 unique char ...    
        for (int unq_char = 1 ;unq_char <= 26 && unq_char*k <= end-start+1 ; unq_char++){ 
            vector<int>count (26,0);
            int goodBoy = 0;
            // now starting sliding window 
            int i = start;
            int window_length = 0;
            for(int j = start ; j <= end ; j++){
                char ch = word[j];
                count[ch-'a']++;
                if(count[ch-'a'] == k) goodBoy++;
                else if (count[ch-'a'] == k+1){
                    goodBoy--;
                }

                if( j - i + 1 > unq_char*k) { // now its time to shift the window 
                    if(count[word[i]-'a'] == k) goodBoy--;
                    else if (count[word[i]-'a'] == k+1){
                        goodBoy++;
                    }
                    count[word[i]-'a'] -- ;
                    i++;
                }
                if (j - i + 1 == unq_char * k && goodBoy == unq_char) result++;
            }
        }  
        return result;
    }

    int countCompleteSubstrings(string word, int k) {
        int n = word.size();

        //  where cond 2 will not be satis fied there 
        // draw a border  aa | ddee | kk | at lst there is also a border
        int last = 0; // start of each block 
        int result = 0;
        for(int i = 1;i <= n ;i++){
            if(i==n || abs (word[i] - word[i-1]) > 2){ // border
                result += solve (last , i-1 , word , k);
                last = i;
            } 
        }
        return result;
    }
};
