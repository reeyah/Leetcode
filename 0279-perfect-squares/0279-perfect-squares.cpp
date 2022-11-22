class Solution {
public:
    int numSquares(int n) {
        if(n<=0)
            return 0;
        vector<int>cntPerfectSqrs(n+1, INT_MAX);
        cntPerfectSqrs[0]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++)
                cntPerfectSqrs[i]=min(cntPerfectSqrs[i], cntPerfectSqrs[i-j*j]+1);
        }
        return cntPerfectSqrs[n];
    }
};