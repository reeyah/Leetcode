class Solution {
public:
    // MEMOIZATION
//     int fib(int n, vector<int>&dp){
//         if(n < 2){
//             dp[n] = n;
//             return dp[n];
//         }
//         if(dp[n] != -1)
//             return dp[n];
//         dp[n] = fib(n-1, dp) + fib(n-2, dp);
        
//         return dp[n];
//     }
    
    int fib(int n) {
        // RECURSION
        // if(n==0)
        //     return 0;
        // if(n==1)
        //     return 1;
        // return fib(n-1)+fib(n-2);
        
        // MEMOIZATION
        // vector<int>dp(n+1, -1);
        // fib(n, dp);
        
        //TABULATION
        // vector<int>dp(n+1);
        // dp[0] = 0;
        // if(n>0)
        //     dp[1] = 1;
        // for(int i=2; i<=n; i++)
        //     dp[i] = dp[i-1] + dp[i-2];
        // return dp[n];
        if(n<2)
            return n;
        
        int a = 0, b = 1, sum = 0;
        for(int i = 2; i<=n; i++){
            sum = a + b;
            a = b;
            b = sum;
        }
        
        return sum;
    }
};