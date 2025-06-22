class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for(int i=0; i<s.size(); i+=k){
            string temp = s.substr(i, k);
            int t = temp.size();
            if(t != k) {
                while(t<k) {
                    temp += fill;
                    t++;
                }
            }
            res.push_back(temp);
        }

        return res;
    }
};