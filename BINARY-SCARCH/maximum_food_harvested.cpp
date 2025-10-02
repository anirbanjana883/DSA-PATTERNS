2106. Maximum Fruits Harvested After at Most K Steps

class Solution {
public:
/*
Time: O(n + k * log n)
Space: O(n)
*/
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefixSum(n);
        vector<int> positions(n);

        for (int i = 0; i < n; i++) {
            positions[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFruits = 0;

        for (int d = 0; d <= k; d++) {
            // Case 1: Move d left, then (k - 2*d) right
            int leftPos = startPos - d;
            int rightPos = startPos + (k - 2 * d);
            if (leftPos <= rightPos) {
                int l = lower_bound(positions.begin(), positions.end(), leftPos) - positions.begin();
                int r = upper_bound(positions.begin(), positions.end(), rightPos) - positions.begin() - 1;
                if (l <= r)
                    maxFruits = max(maxFruits, prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0));
            }

            // Case 2: Move d right, then (k - 2*d) left
            leftPos = startPos - (k - 2 * d);
            rightPos = startPos + d;
            if (leftPos <= rightPos) {
                int l = lower_bound(positions.begin(), positions.end(), leftPos) - positions.begin();
                int r = upper_bound(positions.begin(), positions.end(), rightPos) - positions.begin() - 1;
                if (l <= r)
                    maxFruits = max(maxFruits, prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0));
            }
        }

        return maxFruits;
    }
};
