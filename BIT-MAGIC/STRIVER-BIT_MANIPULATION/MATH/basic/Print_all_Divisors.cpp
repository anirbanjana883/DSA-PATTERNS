all divisors of a Number


class Solution { // tle
  public:
    void print_divisors(int n) {
        for(int i = 1; i <= n ; i++){
            if( n % i == 0) cout << i << " ";
        }
    }
};

class Solution {
  public:
    // time o(sqrt(n))
    vector<int> print_divisors(int n) {
        vector<int>ans;
        //             i * i  better approach then sqrt stl
        for(int i = 1; i <= sqrt(n) ; i++){
            // 12 * 3 = 36
            // again 3 * 12 = 36 counted twice
            if( n % i == 0) {
                ans.push_back(i);
                if( n % i != i){ // avoid duplication
                    ans.push_back(n / i);
                }
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};