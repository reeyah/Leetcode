class Solution {
public:
    string clearDigits(string s) {
        string res;
        stack<int>pos;
        for (int i=0; i<s.size(); i++) {
            if (s[i]>='0' && s[i]<='9')
                pos.pop();
            else 
                pos.push(i);
        }

        while(!pos.empty()){
            res+= s[pos.top()];
            pos.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};