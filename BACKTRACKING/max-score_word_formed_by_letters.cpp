1255. Maximum Score Words Formed by Letters

class Solution {
    public:
        // t.c O(l*(2^N))
        int maxScore;
        int n;
        void solve(int idx,vector<int>& score,vector<string>& words, vector<int>&freq,int current_score){
            maxScore=max(maxScore,current_score);
            if(idx==n) return ;
            // we have to check if we can take this char or not 
            int j=0;
            int tempScore=0;
            vector<int>tempFreq=freq;
            while(j<words[idx].length()){
                char ch=words[idx][j];
    
                tempFreq[ch-'a']--;
                tempScore+=score[ch-'a'];
    
                if(tempFreq[ch-'a']<0) break;
                j++;
            }
            // take
            if(j==words[idx].length()){
                // if we take then we will use the updated freequency
                solve(idx+1,score,words,tempFreq,current_score+tempScore);
            }
            // not take
            solve(idx+1,score,words,freq,current_score);
        }
        int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
            // t.c O(L*(2^N)) L-avg length of each word
            vector<int>freq(26,0);
            for(auto &ch:letters){
                freq[ch-'a']++;
            }
             maxScore=0;
            n=words.size();
            solve(0,score,words,freq,0);
            return maxScore;
        }
    };