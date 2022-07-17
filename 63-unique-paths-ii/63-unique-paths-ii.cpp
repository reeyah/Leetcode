class Solution {
public:
    int unique(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j, vector<vector<int>> &dp){
        if(obstacleGrid[i][j]){
           return 0; 
        }
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j] !=-1)
            return dp[i][j];
        
        int right = 0, down = 0;
        if(i<m-1)
           down = unique(obstacleGrid, m, n, i+1, j, dp);
        if(j<n-1)
            right = unique(obstacleGrid, m, n, i, j+1, dp);
        return dp[i][j]=right+down;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
//         for(int i = 0; i<m; i++)
//             for(int j=0; j<n; j++){
//                 if(obstacleGrid[i][j])
//                    dp[i][j] = 0;
//                 else if(i == 0 && j == 0)
//                     dp[i][j] = 1;
                
                
//                 else dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         return dp[m-1][n-1];
         return unique(obstacleGrid, m, n, 0, 0, dp);
    }
};