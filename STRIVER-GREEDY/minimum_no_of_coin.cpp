Minimum number of Coins


class Solution {
public:
// time complexity: O(n)
// space complexity: O(1)
    vector<int> minPartition(int n) {
        vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> result;
        int i = 0;
        while (n > 0 && i < coins.size()) {
            if (coins[i] <= n) {
                int numCoins = n / coins[i];
                for (int j = 0; j < numCoins; ++j) {
                    result.push_back(coins[i]);
                }
                n -= numCoins * coins[i];
            }
            ++i;
        }
        return result;
    }
};