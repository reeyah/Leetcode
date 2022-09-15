class Solution {
public:
    int insertCount(string&s, int i, int j, vector<vector<int>>&dp){
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s[j])
            return dp[i][j] = insertCount(s, i+1, j-1,dp);
        return dp[i][j] = min(insertCount(s, i+1, j, dp), insertCount(s, i, j-1, dp))+1;
        
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return insertCount(s, 0, s.length()-1, dp);
    }
};