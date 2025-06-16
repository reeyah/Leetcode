class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int keep = num.size() - k;
        for(auto digit: num) {
            while(!res.empty() && k && res.back() > digit) {
                res.pop_back();
                k--;
            }

            res.push_back(digit);
        }
        res.erase(keep, string::npos);

        int s = 0;
        while (s<res.size()-1 && res[s]=='0')  
            s++;
        res.erase(0, s);

        return res=="" ? "0":res;
    }
};