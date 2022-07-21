class Solution {
public:
    int helper(vector<int>& coins, int amount, int i, vector<vector<int>>&dp){
        if(i==0){
            return amount%coins[0]==0;
        }
        if(dp[i][amount]!= -1)
            return dp[i][amount];
        
        int notTake = helper(coins, amount, i-1, dp);
        int take = 0;
        if(coins[i]<=amount)
            take = helper(coins, amount-coins[i], i, dp);
        
        return dp[i][amount] = notTake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        
        return helper(coins, amount, n-1, dp);
    }
};