class Solution {
public:
//     int lengthCalc(int ind1, int ind2, string text1, string text2, vector<vector<int>>&dp){
//         if(ind1< 0 || ind2<0)
//             return 0; 
        
//         if(dp[ind1][ind2] != -1)
//             return dp[ind1][ind2];
        
//         if(text1[ind1] == text2[ind2])
//             return dp[ind1][ind2] = 1 + lengthCalc(ind1-1, ind2-1, text1, text2, dp);
//         int left = lengthCalc(ind1-1, ind2, text1, text2, dp);
//         int right = lengthCalc(ind1, ind2-1, text1, text2, dp);
        
//         return dp[ind1][ind2] = max(left, right);
        
//     }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2=text2.length();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
        // return lengthCalc(n1-1, n2-1, text1, text2, dp);
        for(int i1 = 1; i1<=n1; i1++){
            for(int i2=1; i2<=n2; i2++){
                if(text1[i1-1]==text2[i2-1])
                    dp[i1][i2] = 1 + dp[i1-1][i2-1];
                else dp[i1][i2] = max(dp[i1-1][i2], dp[i1][i2-1]);
            }
        }
        
        return dp[n1][n2];
    }
};