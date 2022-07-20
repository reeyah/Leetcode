class Solution {
public:
    // DOESN'T WORK FOR NEG NOS.
    int minimumDifference(vector<int>& nums) {
//         int n = nums.size();
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         vector<vector<bool>>dp(nums.size(), vector<bool>(sum+1, false)); 
        
//         for(int i=0; i<n; i++)
//             dp[i][0] = true;
//         if(nums[0]<=sum)
//             dp[0][nums[0]] = true;
        
//         for(int i=1; i<n; i++){
//             for(int j=0; j<=sum; j++){
//                 if(j<nums[i])
//                     dp[i][j] = dp[i-1][j];
//                 else dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
//             }
//         }
        
//         int mini = 1e9;
//         for(int s1=0; s1<=sum/2; s1++){
//             if(dp[n-1][s1])
//                 mini = min(mini, abs(sum-s1)-s1);
//         }
        
//         return mini;
        
        int n = nums.size()/2; 
        vector<int> left(nums.begin(), nums.begin()+n), right(nums.begin()+n, nums.begin()+2*n); 
        
        vector<vector<int>> vals(n+1); 
        for (int mask = 0; mask < (1<<n); ++mask) {
            int diff = 0, key = __builtin_popcount(mask); 
            for (int i = 0; i < n; ++i) 
                diff += (mask & (1 << i)) ? left[i] : -left[i]; 
            vals[key].push_back(diff); 
        }
        
        for (auto& v : vals) sort(v.begin(), v.end()); 
        
        int ans = INT_MAX; 
        for (int mask = 0; mask < (1<<n); ++mask) {
            int diff = 0, key = n - __builtin_popcount(mask); 
            for (int i = 0; i < n; ++i) 
                diff += (mask & (1 << i)) ? right[i] : -right[i]; 
            auto it = lower_bound(vals[key].begin(), vals[key].end(), -diff); 
            if (it != vals[key].begin()) ans = min(ans, abs(diff + *prev(it))); 
            if (it != vals[key].end()) ans = min(ans, abs(diff + *it)); 
        }
        return ans; 
    }
    
};