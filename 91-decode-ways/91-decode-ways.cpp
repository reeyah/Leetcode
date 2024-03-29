class Solution {
public:
    int numDecodings(string str) {
        int n = str.length();
		if (str[0] == '0') return 0;
		if(n==0 || n==1) return 1; 
		vector<int>dp(n+1);
		dp[0]=dp[1]=1; //base
		for(int i=2; i<=n; i++){
		    if(str[i-1]!='0')
		        dp[i]+=dp[i-1];
		     if(str[i-2]!='0')
		     if(((str[i-2]-'0')*10 + (str[i-1]-'0'))<=26)
		        dp[i]+=dp[i-2];
		}
		return dp[n];
    }
};