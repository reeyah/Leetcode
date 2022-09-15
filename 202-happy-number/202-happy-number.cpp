class Solution {
public:
    bool isHappy(int n) {
        // set<int>s
        while(n>9){
            string s = to_string(n);
            n = 0;
            for(auto c:s){
                n+=pow((c-'0'),2);
            }
            if(n==1)
                return true;
        }
        return n==1||n==7? true : false;
    }
};