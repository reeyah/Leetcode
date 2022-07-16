class Solution {
public:
    int climbStairs(int n) {
        //FIBONACCI 
        if(n<3)
            return n;
        int a = 1, b = 2; //BASE CONDITION DIFFERENT
        while (n-- > 2) {
            a = (b += a) - a;
        }
        return b;
    }
};