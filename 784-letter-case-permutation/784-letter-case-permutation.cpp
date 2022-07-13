class Solution {
public:
    void subs(string s, int i, vector<string>&p){
        if(i==s.length()){
            p.push_back(s);
            return;
        }
        
        subs(s, i+1, p);
        if(isalpha(s[i])){
            s[i] ^= 32;
            subs(s, i+1, p);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string>p;
        subs(s, 0, p);
        return p;
    }
};