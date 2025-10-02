3403. Find the Lexicographically Largest String From the Box I 

- laxicographically largest - that comes last at the dictionary order
 abc < abd 
 d > abc

trick
 let you have a string  dbca and you have 3 friends
  f1  f2  f3 
  db <-c <-a so the laxicographically largest string is db  

class Solution {
public:
    // time complexity o(n^2)
    // space complexity o(1)
    string answerString(string word, int numFriends) {
        int n=word.size();
        // edge case
        if(numFriends==1) return word;
        int largest_possible=n-(numFriends-1);
        string result="";
        for(int i=0;i<n;i++){
            int availableLength=min(largest_possible,n-i);
            // creating all substring of length
            // availableLength and taking maximum of them
            result=max(result,word.substr(i,availableLength));
        }
        return result;
    }
};
