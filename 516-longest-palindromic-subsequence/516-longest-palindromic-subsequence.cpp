class Solution {
public:
    int longest(string &t1, int i, int j, vector<vector<int>>&dp){
        if(i>= t1.size() || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(t1[i] == t1[j])
            return dp[i][j] = 1 + longest(t1,i+1,j-1,dp);
        return dp[i][j] = max(longest(t1,i+1,j,dp), longest(t1,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));
        return longest(s, 0, s.size()-1, dp);
    }
};