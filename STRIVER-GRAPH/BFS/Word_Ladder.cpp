127. Word Ladder

class Solution {
public:
    // time o( n * l)
    // space o( n * l)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());  
        if (st.find(endWord) == st.end()) return 0; 
        st.erase(beginWord);

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            string word = p.first;
            int step = p.second;  

            if (word == endWord) {
                return step;
            }

            for (int i = 0; i < word.length(); i++) {  
                char original = word[i];
                for (char newC = 'a'; newC <= 'z'; newC++) {
                    word[i] = newC;
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, step + 1});
                    }
                }
                word[i] = original; 
            }
        }

        return 0;
    }
};
