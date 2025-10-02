2981. Find Longest Special Substring That Occurs Thrice I

solution => https://youtu.be/fDUPCtPqzss?si=kpPm9i7k69eTgCK_

A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.

Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.

broute force approach-->

time complexity: O(N^3)
space complexity: O(N^2)

class Solution {
public:
    int maximumLength(string s) {  //O(N)
        // find all the spacial substring(that has onlt one type of character)
        // then find freequency of all substring
        // find longrst substring that has freequency >= 3
        int n = s.length();
        unordered_map<string, int> mp; // string ,freequency
        for (int i = 0; i < n; i++) {
            string curr = "";
            for (int j = i; j < n; j++) {  //O(N)
                // make sure all substring should have onr type character
                // for 1st time curr will be empty
                if (curr.empty() || curr.back() == s[j]) {
                    curr.push_back(s[j]);
                    mp[curr]++;  //O(N)  during copying the current string in map
                } else {
                    // if different character then no need to add
                    break;
                }
            }
        }
        // find longrst substring that has freequency >= 3
        int result=0;
        for(auto it :mp){
            string str=it.first;
            int count =it.second;
            if(count >=3 && str.length()>result){
                result=str.length();
            }
        }
        return result==0 ? -1 : result;
    }
};

better approach-->

time complexity: O(N^2*log(N))
space complexity: O(N^2)

****** NOTE in cpp you can not take pair in unordered map ###############################

in the prev approach we are pusing the string that are not spacial 
so are westing aur space
also we are copying all the substring into the map so time complexity also increases  O(N^3)

since in spacila substring we have only one character 
so we will store like this  {{character , lengthOfSunstring},freequency}

class Solution {
public:
    int maximumLength(string s) { // better approach
        // find all the spacial substring(that has onlt one type of character)
        // then find freequency of all substring
        // find longrst substring that has freequency >= 3
        // we will store like this  {{character , lengthOfSunstring},freequency}
        // thus we acn improve t.c to O(N^2)
        int n = s.length();
        map<pair<char, int>, int> mp; // string ,freequency
        for (int i = 0; i < n; i++) {  // O(N)
            char currChar = s[i];
            int lenOfCurrChar = 0;
            for (int j = i; j < n; j++) { // O(N)
                // make sure all substring should have onr type character
                // for 1st time curr will be empty
                if (currChar == s[j]) {
                    // means next char is also same as prev
                    // length increase
                    lenOfCurrChar++;
                    // freequency updated
                    mp[{currChar, lenOfCurrChar}]++;  //O(logN) as insrertion in map take O(logN)
                } else {
                    // if different character then no need to add
                    break;
                }
            }
        }
        // find longrst substring that has freequency >= 3
        int result = 0;
        for (auto it : mp) {
            //{{character , lengthOfSunstring},freequency}
            // char ch =it.first.first; no need
            int lenOfCurrSubstr = it.first.second;
            int freq = it.second;
            if (freq >= 3 && lenOfCurrSubstr > result) {
                result = lenOfCurrSubstr;
            }
        }
        return result == 0 ? -1 : result;
    }
};

optimal  approach-->

time complexity: O(26*N)~O(N)
space complexity: O(26*N)~O(N)

aaaa    
         a <--- a a <--- a a a <--- a a a a
      1+1+1+1   1+1+1     1+1         1

      we have seen  a a a in  a a a a also its count is 1+1
      we have seen  a a  in  a a a and a a a a also its count is 1+1+1
       so 

    count of a     1 <---    2 <---   3     <--- 4 most efficient way 
     freequency  1+1+1+1   1+1+1     1+1         1

     similarly you can store datat of substring in 2D array 
     when you asked same type of question
     row --> character 
     column --> length of spacial substring (count of same character )



class Solution {
public:
    int maximumLength(string s) { // optimal aproach
        // we will create a @D array of data
        // thus we acn improve t.c to O(N)
        int n = s.length();
        //  to store the data of each distince character
        // row --> character
        // column --> length of spacial substring (count of same character )
        vector<vector<int>> matrix(26, vector<int>(n + 1, 0));

        char prev_char = s[0];
        int lengthOfCurrChar = 0;

        // iterating over he string
        // and fill the 2D matrix
        for (int i = 0; i < n; i++) {
            char curr_char = s[i];

            // if current an dprevious character is same then length
            //  increase and update it into the matrix
            if (curr_char == prev_char) {
                lengthOfCurrChar++;
                // row --> character
                // column --> length of spacial
                //    substring (count of same character(freequency) )
                matrix[curr_char - 'a'][lengthOfCurrChar]++;
            } else {
                // we have found a new character
                // so length of current char reste to 1
                lengthOfCurrChar = 1;
                matrix[curr_char - 'a'][lengthOfCurrChar]++;
                // updating the prev char bcoz this is a new char
                prev_char = curr_char;
            }
        }

        int result = 0;
        for (int i = 0; i < 26; i++) { // since we have only loqer case
            int cumulativeSum = 0;
            // iterating from the back so col
            // to calulate the freequency from bigger length spacial substring
            for (int j = n; j >= 1; j--) {
                // updating the cumulative sum
                cumulativeSum += matrix[i][j];
                // if we found any freequency greater then 3
                if (cumulativeSum >= 3) {
                    // update the result
                    result = max(result, j);
                    // since we found the biggest length of spacila substring
                    // no furter need to see bcoz we
                    // iterating from bigger to smaller length
                    break;
                }
            }
        }
        return result == 0 ? -1 : result;
    }
};