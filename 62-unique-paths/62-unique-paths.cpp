class Solution {
public:
    
    //RECURSION, TLE
//     int uniquePaths(int m, int n) {
//         if(m==1 || n==1)
//             return 1;
//         int left = uniquePaths(m-1, n);
//         int right = uniquePaths(m, n-1);
        
//         return left + right;
//     }
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0; i<m ; i++)
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m-1][n-1];
    }
};