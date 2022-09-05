class Solution {
public:
    bool check(vector<int>&arr, int i, int k, vector<vector<int>>&dp){
        if(k==0)
            return true;
        if(i==arr.size() || k<0)
            return false;
        if(dp[i][k]!=-1)
            return dp[i][k];
        dp[i][k] = check(arr, i+1, k-arr[i], dp) || check(arr, i+1, k, dp);
        return dp[i][k];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1)
            return false;
        vector<vector<int>>dp(nums.size(), vector<int>(sum/2+1,-1));
        return check(nums, 0, sum/2, dp);
    }
};