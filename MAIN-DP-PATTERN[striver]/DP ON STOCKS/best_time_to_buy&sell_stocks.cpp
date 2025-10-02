121. Best Time to Buy and Sell Stock 1

# buy once and sell once 

time complexity o(n)
space compelxity o(1)

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int maxProfit=0;
            int minBuyPrice=prices[0];
            for(int i=1;i<prices.size();i++){
                int profit=prices[i]-minBuyPrice;
                maxProfit=max(maxProfit,profit);
                minBuyPrice=min(minBuyPrice,prices[i]); // dp
            }
            return maxProfit;
        }
    };