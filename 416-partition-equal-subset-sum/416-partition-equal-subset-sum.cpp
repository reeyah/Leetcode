class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if ((sum & 1) == 1) //odd total
            return false;
        sum /= 2;
        
        int n = nums.size();
        vector<vector<bool>>dp(n, vector<bool>(sum+1, false));
    
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        
        if(nums[0]<=sum)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < sum+1; j++) {
                if(nums[i]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][sum];
    }
};