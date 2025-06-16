class Solution {
public:
    bool isPalindrome(int x) {
        // if (x < 0)
        //     return false;
        // if (x == 0)
        //     return true;
        // if (x % 10 == 0)
        //     return false;
            
        // int reverseHalf = 0;
        // while(x > reverseHalf) {
        //     reverseHalf = reverseHalf * 10 + x % 10;
        //     x /= 10;
        // }

        // //cout<<x<<" "<<reverseHalf<<endl;

        // return x == reverseHalf || x == reverseHalf/10;

        string num = to_string(x);

        for(int i=0, j=num.size()-1; i<j; i++, j--) {
            if(num[i] != num[j])
                return false;
        }

        return true;
    }
};