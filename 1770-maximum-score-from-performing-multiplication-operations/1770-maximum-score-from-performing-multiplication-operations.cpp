class Solution {
public:
    int calc(vector<int>&n, vector<int>&m, int i, int j, int k, vector<vector<int>>&dp){
        if(k==m.size())
            return 0;
        if(dp[i][k]!=INT_MIN)
            return dp[i][k];
        return dp[i][k] = max(calc(n,m,i+1,j,k+1,dp)+n[i]*m[k], calc(n,m,i,j-1,k+1,dp)+n[j]*m[k]);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int maxScore = 0;
        vector<vector<int>>dp(multipliers.size(), vector<int>(multipliers.size(), INT_MIN));
        return calc(nums, multipliers, 0, nums.size()-1, 0, dp);
    }
};