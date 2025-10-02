60. Permutation Sequence

broute force approach : 

generate all possible combination -> sort -> return k-1 th element
TLE

optimised approach :
see explanation again 😂 extream tough to understand 

class Solution {
public:
    // time o(n^2)
    // space o(n)
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>numbers;
        for(int i = 1; i < n ;i ++){
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        // for 0 based indexing 
        k = k - 1;
        while(true){
            ans += to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if( numbers.size() == 0) break;
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};