921. Minimum Add to Make Parentheses Valid

class Solution {
public:
    // t o(N)
    // s o(N)
    int minAddToMakeValid(string s) {
        stack<char>st;
        int closing_br_needed=0;
        //  we need a ver for opening bracket count also 
        for(auto &it : s ){
            if(it=='(') st.push(it);
            else{  // ')'
                if(st.empty()) closing_br_needed++ ;
                else{
                    st.pop();
                }
            }
        }
        return st.size()+closing_br_needed;
    }
};

insted of taAking a stack we can use a variable to keep track of the size of imaginary stack

class Solution {
public:
    // t o(N)
    // s o(1)
    int minAddToMakeValid(string s) {
        int size_of_imaginary_stack=0;
        int closing_br_needed=0;
        //  we need a ver for opening bracket count also 
        for(auto &it : s ){
            if(it=='(') size_of_imaginary_stack ++;
            else{  // ')'
                if(size_of_imaginary_stack ==0) closing_br_needed++ ;
                else{
                    size_of_imaginary_stack --;
                }
            }
        }
        return size_of_imaginary_stack + closing_br_needed;
    }
};