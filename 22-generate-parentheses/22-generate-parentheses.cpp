class Solution {
public:
    void rec(int n, int m, string &s, vector<string>&ans){
        if(n==0 && m==0){
            ans.push_back(s);
            return;
        }
        
        if(n>0){
            s+="(";
            rec(n-1, m, s, ans);
            s.pop_back();
        }
        if(m>n){
            s+=')';
            rec(n, m-1, s, ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        rec(n, n, s, ans);
        return ans;
    }
};