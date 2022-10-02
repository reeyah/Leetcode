class Solution {
public:
    int numRolls(int n, int k, int target, vector<vector<int>>&dp, int res = 0){
        if (n == 0 || target == 0) 
            return n == target;
        if(dp[n][target] != -1)
            return dp[n][target];
        for (auto i = 1; i <= k && i<=target; ++i)
            res = (res + numRolls(n - 1, k, target - i, dp)) % 1000000007;
        return dp[n][target]=res;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return numRolls(n, k, target, dp);
    }
};