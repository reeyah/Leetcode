class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int>dp(n);
        int maxi = 0;
        for(int i=0; i<n ; i++){
            dp[i]=matrix[0][i]-'0';
            maxi=max(dp[i], maxi);
        }
        for(int i=1; i<m; i++){
            int diag = dp[0];
            dp[0] = matrix[i][0]-'0';
            maxi=max(maxi, dp[0]);
            for(int j=1; j<n; j++){
                int temp = dp[j];
                if(matrix[i][j]=='1')
                    dp[j]= min(min(dp[j], dp[j-1]),diag) + 1;
                else dp[j]=0;
                maxi=max(maxi, dp[j]);
                diag = temp; 
            }
        }
        
        return maxi*maxi;
    }
};