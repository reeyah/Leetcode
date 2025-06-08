class Solution {
public:
    int numDecodings(string str) {
        int n = str.length();
		if (str[0] == '0')  // 07 -> cannot be decoded
            return 0;
		if(n==0 || n==1) // 0 non-constraint, if str.size == 1 then just 1 way to decode
            return 1;   
		
        int prev2 = 1, prev1 = 1; //base
		
        //dp[0]=dp[1]=1; //base
		for(int i=2; i<=n; i++){
            int curr = 0;
		    if(str[i-1]!='0') // if num to be added is 0 it wont stand on its own and without pair will eventually result in 0 possible decodings
		        curr = prev1;
		    if(str[i-2]!='0') // >=10
		        if(stoi(str.substr(i-2,2)) <= 26)
		            curr += prev2;
            prev2 = prev1;
            prev1 = curr;
		}
		return prev1;
    }
};