2785. Sort Vowels in a String


appproach 1 :

class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        string onlyVowel = "";
        
        // Extract only vowels from the string
        for(int i = 0; i < n; i++) {
            char c = s[i];
            // Check if character is a vowel
            if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
               c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                onlyVowel += c;
                s[i] = '#'; // Mark vowel position
            }
        }
        
        // Sort the vowels
        sort(onlyVowel.begin(), onlyVowel.end());
        
        // Replace marked positions with sorted vowels
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '#') {
                s[i] = onlyVowel[j++];
            }
        }
        
        return s;
    }
};

appproach 2:  counnt sort technique ... 

class Solution {
public:
    bool isVowel(char c){
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
               c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
    string sortVowels(string s) {
        int n = s.size();
        
        // Count all vowels in the string
        unordered_map<char, int> mp;
        for(auto &it : s){
            if(isVowel(it)){
                mp[it]++;
            }
        }
        
        string ref = "AEIOUaeiou";
        int j = 0;
        
        for(int i = 0; i < n; i++){
            if(isVowel(s[i])){
                // Find the next available vowel in sorted order
                while(j < ref.size() && mp[ref[j]] == 0) {
                    j++;
                }
                
                // Replace the current vowel with the next sorted vowel
                s[i] = ref[j];
                mp[ref[j]]--;
            }
        }
        return s;
    }
};