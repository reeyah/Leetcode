class Solution {
public:
    int fib(int n, vector<int>&dp){
        if(n < 2){
            dp[n] = n;
            return dp[n];
        }
        if(dp[n] != -1)
            return dp[n];
        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        
        return dp[n];
    }
    
    int fib(int n) {
        // RECURSION
        // if(n==0)
        //     return 0;
        // if(n==1)
        //     return 1;
        // return fib(n-1)+fib(n-2);
        
        // MEMOIZATION
        vector<int>dp(n+1, -1);
        fib(n, dp);
        return dp[n];
    }
};