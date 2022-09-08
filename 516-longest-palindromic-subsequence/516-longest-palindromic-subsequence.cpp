class Solution {
public:
    int longest(string &t1, string &t2, int i, int j, vector<vector<int>>&dp){
        if(i>= t1.size() || j>=t2.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(t1[i] == t2[j])
            return dp[i][j] = 1 + longest(t1,t2,i+1,j+1,dp);
        return dp[i][j] = max(longest(t1,t2,i+1,j,dp), longest(t1,t2,i,j+1,dp));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));
        string r = s;
        reverse(r.begin(), r.end());
        return longest(s, r, 0, 0, dp);
    }
};