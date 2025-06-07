class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<stack<int>> occ(26);

        for(int i=0; i<n; i++) {
            if(s[i]=='*') {
                for(int j=0; j<26; j++) {
                    if(!occ[j].empty()) {
                        s[occ[j].top()] = '*';
                        occ[j].pop();
                        break;
                    }
                }
            } else {
                occ[s[i]-'a'].push(i);
            }
        }

        string res = "";
        for(int i=0; i<n; i++){
            if(s[i]!='*')
                res+=s[i];
        }

        return res;
    }
};