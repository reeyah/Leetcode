class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int tar) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), -tar) ;
        if(target < 0 || target & 1)
            return 0;
        target /=2;
        vector<vector<int>>dp(nums.size(), vector<int>(target+1, 0)); 
        if(nums[0]==0)
            dp[0][0] = 2;
        else dp[0][0] = 1;
 
        if(nums[0] != 0 && nums[0] <= target)
            dp[0][nums[0]] = 1;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=target; j++){
                if(j<nums[i])
                    dp[i][j] = dp[i-1][j];
                else dp[i][j] = (dp[i-1][j] + dp[i-1][j-nums[i]]);
            }
        }
    
    return dp[n-1][target];
    }
};