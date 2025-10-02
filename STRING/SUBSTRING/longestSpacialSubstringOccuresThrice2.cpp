2982. Find Longest Special Substring That Occurs Thrice II

solution => https://youtu.be/fDUPCtPqzss?si=kpPm9i7k69eTgCK_

############################# very imp question #####################################

basically it is the same question as previous 2981 but with high constreain 
so optimised solution will work only


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