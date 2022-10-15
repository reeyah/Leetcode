class Solution {
    int calcLen(int len){
        if (len == 0) return 0;
        else if (len == 1) return 1;
        else if (len < 10) return 2;
        else if (len < 100) return 3;
        else return 4;
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        vector<vector<int>>dp(n+1, vector<int>(k+1));
        for (int i = 1; i <= n; i++)
            for(int j=0; j<=k; j++)
            dp[i][j] = INT_MAX;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= k; j++){
                if (j > 0) 
                    dp[i][j] = dp[i - 1][j - 1];
                int removed = 0, cnt = 0, p;
                for (p = i; p > 0; p--){
                    if (s.at(p - 1) == s.at(i - 1)) 
                        cnt++;
                    else if (++removed > j) 
                        break;
                    dp[i][j] = min(dp[i][j], dp[p - 1][j - removed] + calcLen(cnt));
                }
            }
        }
        return dp[n][k];
    }
};