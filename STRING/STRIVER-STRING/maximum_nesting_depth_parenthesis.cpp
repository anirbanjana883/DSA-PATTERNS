1614. Maximum Nesting Depth of the Parentheses

@@  when ever nay parenthesis question is seen once think about stack 


A string is a valid parentheses string (denoted VPS ) if is meets any one of the following:

It is an empty string "", or a single character not equals to " ( "  or  " ) " ,
It can be written as AB (A concatenated with B ),
where A and B are VPS's , or
It can be written as (A) , where A is a VPS.
We can similarly define the nesting depth depth (S) of any VPS S as follows:

depth ("") = 0
depth (C) = 0, where C is a string with a single character excluding "(" and ")" ,
depth (A + B) = max (depth (A) , depth (B)) , where A and B are VPS's.
depth ( "(" + A + ")" ) = 1 + depth (A) , where A is a VPS.
For example , "" , " ( ) ( ) " , and " ( ) ( ( ) ( ) ) " and VPS's (with nesting depths 0 , 1, and 2), and " ) ( " and " ( ( ) "   are not VPS's.

class Solution {
public:
    // t o(n)
    // s o(n)
    int maxDepth(string s) {
        //  at max how many open bracket seen together 
        stack <int> st;
        int maxDepth = 0;
        for(auto &it : s){
            if(it== '(') {
                st.push(it);
                maxDepth = max (maxDepth , (int)st.size());
            }else if (it== ')'){
                st.pop();
            }
        }
        return maxDepth;
    }
};

class Solution {
public:
    // t o(n)
    // s o(1)
    int maxDepth(string s) {
        //  at max how many open bracket seen together 
        int size = 0;
        int maxDepth = 0;
        for(auto &it : s){
            if(it== '(') {
                size++;
                maxDepth = max (maxDepth , size);
            }else if (it== ')'){
                size--;
            }
        }
        return maxDepth;
    }
};