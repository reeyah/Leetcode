class Solution {
public:
    int climbStairs(int n) {
        if (n==0 || n==1)
            return 1;
        int prev = 1, prev2= 1, curr;

        for(int i=2; i<=n ; i++) {
            curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }

        return curr;
            
    }
};