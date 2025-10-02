2197. Replace Non-Coprime Numbers in Array

class Solution {
public:
    // Time Complexity: O(N⋅logM)
    // Space Complexity: O(N)
    int lcm(int a, int b, int gCd) {
        if (a == 0 || b == 0)
            return 0;
        return abs((a / gCd) * b); //( a * b ) / gcd <-(actually)
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for (auto& it : nums) {
            result.push_back(it);
            while (result.size() > 1) {
                int last = result.back();
                result.pop_back();

                int sec_last = result.back();

                int common_div = gcd(last, sec_last);

                if (common_div > 1) {
                result.back() = lcm(last,sec_last,common_div);
                } else {
                    result.push_back(last);
                    break;
                }
            }
        }
        return result;
    }
};