class Solution {
public:
    int helper(vector<int>& coins, int amount, int i, vector<vector<int>>&dp){
        if(i==0){
            if(amount%coins[0]==0)
                return amount/coins[0];
            return 1e9;
        }
        if(dp[i][amount]!= -1)
            return dp[i][amount];
        
        int notTake = helper(coins, amount, i-1, dp);
        int take = INT_MAX;
        if(coins[i]<=amount)
            take = 1 + helper(coins, amount-coins[i], i, dp);
        
        return dp[i][amount] = min(notTake, take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        
        int count = helper(coins, amount, n-1, dp);
        if(count>=1e9)
            return -1;
        return count;
    }
};