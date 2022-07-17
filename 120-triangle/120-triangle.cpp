class Solution {
public:
    
    //MEMOIATION
//     int calc(vector<vector<int>>& triangle, int n, int r, int c, vector<vector<int>>& dp){
//         if(r==n-1)
//             return triangle[r][c];
//         if(dp[r][c]!=-1)
//             return dp[r][c];
//         int mini=triangle[r][c];
//         int m = triangle[r].size();
//         mini = mini+min(calc(triangle, n, r+1, c, dp),calc(triangle, n, r+1, c+1, dp));
        
//         return dp[r][c] = mini;
        
//     }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>minlen(triangle.back());
        // vector<vector<int>>dp(n, vector<int>(triangle.back().size(), -1));
        for (int layer = n-2; layer >= 0; layer--) {
            for (int i = 0; i <= layer; i++) {
                minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
            }
        }
        return minlen[0];
        
//         return calc(triangle, triangle.size(), 0, 0, dp);
    }
};