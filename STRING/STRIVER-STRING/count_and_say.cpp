38. Count and Say


Given an integer n. Return the nth row of the following look-and-say/count-and-say pattern.
1
11
21
1211
111221
Look-and-Say Pattern:

To generate a member of the sequence from the previous member, read off the digits of the previous member, counting the number of digits in groups of the same digit. For example:

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
1211 is read off as "one 1, one 2, then two 1s" or 111221.
111221 is read off as "three 1s, two 2s, then one 1" or 312211.




Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

you just have to remember n(1)="1"

example  [n=3]----->[n=2]------>[n=1] recursive call
"21<----- "11"  <----- "1"    <----- "
2 bar 1   1 bar 1     0 bar 1

class Solution {
public:
    string countAndSay(int n) {
        // base case 
        if(n==1) return "1";
        // recursn call
        string say=countAndSay(n-1);
        // ans processing
        string result="";
        for(int i=0;i<say.length();i++){
            char ch=say[i];
            int count =1;
            // now cheak how much time the same character has come
            while(i<say.length()-1 && say[i]==say[i+1]){
                count++;
                i++;
            }
            // converting count to string  and char to string
            result+=to_string(count)+string(1,ch);
        }
        return result;
    }
};