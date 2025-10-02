126. Word Ladder II

it is giving memeory limit exceed in leetcode but giving correct ans in gfg

// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
         unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (st.find(endWord) == st.end()) return result; // endWord must be in the wordList

        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> usedInLevel;
        int level = 1;
        int minLevel = INT_MAX;

        unordered_map<string, int> visited;
        visited[beginWord] = 1;

        while (!q.empty()) {
            vector<string> path = q.front();
            q.pop();

            if (path.size() > level) {
                for (const string& word : usedInLevel)
                    st.erase(word);
                usedInLevel.clear();
                level = path.size();
                if (level > minLevel) break;
            }

            string lastWord = path.back();

            if (lastWord == endWord) {
                if (path.size() <= minLevel) {
                    minLevel = path.size();
                    result.push_back(path);
                }
            }

            for (int i = 0; i < lastWord.size(); i++) {
                string temp = lastWord;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (st.find(temp) != st.end()) {
                        vector<string> newPath = path;
                        newPath.push_back(temp);
                        q.push(newPath);
                        usedInLevel.insert(temp);
                    }
                }
            }
        }

        return result;
    }
};