Fractional Knapsack Problem

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // time o ( n + logn)
    // space o ( n)
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          int n = val.size();

        // Step 1: Create ratio vector → pair<value/weight, index>
        vector<pair<double, int>> ratio;
        for (int i = 0; i < n; i++) {
            double r = (double)val[i] / wt[i];  // Cast to avoid integer division
            ratio.push_back({r, i});
        }

        // Step 2: Sort by ratio in descending order
        sort(ratio.begin(), ratio.end(), [](pair<double, int> &a, pair<double, int> &b) {
            return a.first > b.first;
        });

        // Step 3: Greedily take from highest ratio items
        double totalValue = 0.0;
        for (int i = 0; i < n && capacity > 0; i++) {
            int idx = ratio[i].second;
            if (wt[idx] <= capacity) {
                // Take full item
                totalValue += val[idx];
                capacity -= wt[idx];
            } else {
                // Take fraction
                totalValue += val[idx] * ((double)capacity / wt[idx]);
                capacity = 0;
            }
        }

        return totalValue;
    }
};

        


