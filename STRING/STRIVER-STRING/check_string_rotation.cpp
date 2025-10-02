796. Rotate String

class Solution {
public:
// broute force approach
    void rotation_of_string(string& s, int n) {
        char first = s[0];
        for (int i = 0; i<n-1; i++) {
            s[i] = s[i + 1];
        }
        s[n-1] = first;
    }
    bool rotateString(string s, string goal) {
        if (s == goal)
            return 1;
        int n = s.length();
        for (int i = 1; i <= n; i++) { // rotate the string n times
            rotation_of_string(s, n);
            if (s == goal)
                return 1;
        }
        return 0;
    }
};

class Solution {
public:
    // stl  approach

    bool rotateString(string s, string goal) {
        if (s == goal)
            return 1;
        int n = s.length();
        for (int i = 0; i <= n; i++) {
            

            rotate(s.begin() , s.begin()+1 , s.end());

            if (s == goal)
                return 1;
        }
        return 0;
    }
};

class Solution {
public:
    bool rotateString(string s, string goal) { // O(N) time complexity
        int m=s.length();
        int n=goal.length();

        if(s==goal) return 1;
        if(m!=n) return 0;
        /*
        When you concatenate the string with itself (s + s), all possible rotations of s are present as substrings.
         So, just check if goal is a substring of s + s.
        */
        if((s+s).find(goal)!=string::npos){
            return 1;
        }
        return 0;
    }
};