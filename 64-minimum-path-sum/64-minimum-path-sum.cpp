class Solution {
public:
    int calc (vector<vector<int>>& grid, int m, int n, vector<vector<int>>&dp){
        if(m==0 && n==0)
            return grid[m][n];
        if(m<0 || n<0)
            return 1e5;
        if(dp[m][n] != -1)
            return dp[m][n];
        int up=grid[m][n], left = grid[m][n];
            up+= calc(grid, m-1, n, dp);
            left+= calc(grid, m, n-1, dp);
        return dp[m][n] = min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return calc(grid, m-1, n-1, dp);
    }
};