class Solution {
public:
    void rec(int n, int m, string s, vector<string>&ans){
        if(n==0 && m==0){
            ans.push_back(s);
            return;
        }
        
        if(n>0)
            rec(n-1, m+1, s+"(", ans);
        if(m>0)
            rec(n, m-1, s+")", ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        rec(n, 0, s, ans);
        return ans;
    }
};