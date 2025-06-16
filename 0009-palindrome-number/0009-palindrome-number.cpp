class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        if (x % 10 == 0)
            return false;
            
        int reverseHalf = 0;
        while(x > reverseHalf) {
            reverseHalf = reverseHalf * 10 + x % 10;
            x /= 10;
        }

        //cout<<x<<" "<<reverseHalf<<endl;

        return x == reverseHalf || x == reverseHalf/10;
    }
};