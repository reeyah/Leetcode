class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // Greedy shortcut
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i)
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            return profit;
        }

        vector<int> dp(n, 0);     // dp[j] = max profit at day j for current transaction
        for (int t = 1; t <= k; ++t) {
            int maxDiff = -prices[0];
            vector<int> new_dp(n, 0);
            for (int d = 1; d < n; ++d) {
                new_dp[d] = max(new_dp[d - 1], prices[d] + maxDiff);
                maxDiff = max(maxDiff, dp[d] - prices[d]);
            }
            dp = new_dp;  // current row becomes previous row for next t
        }

        return dp[n - 1];
    }
};