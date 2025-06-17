class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost1 = INT_MAX, cost2 = INT_MAX, profit1 = 0, profit2 = 0;

        for(int i=0; i<prices.size(); i++) {
            cost1 = min(cost1, prices[i]);
            profit1 = max(profit1, prices[i]-cost1);

            cost2 = min(cost2, prices[i]-profit1);
            profit2 = max(profit2, prices[i]-cost2);
        }

        return profit2;
    }
};