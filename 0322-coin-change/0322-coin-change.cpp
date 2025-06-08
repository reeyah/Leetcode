class Solution {
public:
    // int helper(vector<int>& coins, int amount, vector<vector<int>>&dp, int i){
    //     if(i==0){
    //         if(amount%coins[0]==0)
    //             return amount/coins[0];
    //         return 1e9;
    //     }
        
    //     if(dp[i][amount]!=-1)
    //         return dp[i][amount];
    //     int notTake = helper(coins, amount, dp, i-1);
    //     int take = INT_MAX;
    //     if(coins[i]<=amount)
    //         take = 1 + helper(coins, amount-coins[i], dp, i);
    //     return dp[i][amount] = min(take, notTake);
    // }
    // 
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=1; i<=amount; i++) {
            for(int j=0; j<coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i-coins[j]]+1, dp[i]);
                }
            }
        }

        return dp[amount] <= amount ? dp[amount] : -1;

        
    }
};