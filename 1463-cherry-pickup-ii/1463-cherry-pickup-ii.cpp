class Solution {
public:
    // int dp[70][70][70] = {};
    int cherryPickup(vector<vector<int>>& grid) {
        // memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int j1 = 0; j1<n; j1++){
            for(int j2 = 0; j2<n; j2++){
                dp[j1][j2]= j1 == j2? grid[m-1][j1] : grid[m-1][j1] + grid[m-1][j2];
            }
        }
        
        for(int row = m-2; row>=0; row--){
            vector<vector<int>>temp(n, vector<int>(n,0));
            for(int j1 = 0; j1<n; j1++){
                for(int j2 = 0; j2<n; j2++){
                    int maxi = 0;
                    for(int it1 = j1-1; it1<= j1+1; it1++){
                        for(int it2 = j2-1; it2<= j2+1; it2++){
                            int val = j1 == j2 ? grid[row][j1] : grid[row][j1] + grid[row][j2];
                            if(it1 >=0 && it2>=0 && it1<n && it2<n)
                                val += dp[it1][it2];
                            maxi = max(maxi, val);
                        }
                    }
                    
                    temp[j1][j2] = maxi;
                }
            }
            dp = temp;
        }
        
        return dp[0][n-1];
        
        // return dfs(grid, m, n, 0, 0, n - 1);
    }
    // int dfs(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2) {
    //     if (r == m) return 0; // Reach to bottom+1 row
    //     if (dp[r][c1][c2] != -1) return dp[r][c1][c2];
    //     int ans = 0;
    //     for (int i = -1; i <= 1; i++) {
    //         for (int j = -1; j <= 1; j++) {
    //             int nc1 = c1 + i, nc2 = c2 + j;
    //             if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
    //                 ans = max(ans, dfs(grid, m, n, r + 1, nc1, nc2));
    //             }
    //         }
    //     }
    //     int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
    //     return dp[r][c1][c2] = ans + cherries;
    // }
};