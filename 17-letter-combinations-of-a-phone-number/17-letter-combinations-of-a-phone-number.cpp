class Solution {
public:
    void dfs(string digits, string &s, vector<string>&ans, int i, const vector<string>&letters){
        if(i==digits.size()){
            ans.push_back(s);
            return;
        }
        for(char j: letters[digits[i]-2-'0']){
            s.push_back(j);
            dfs(digits, s, ans, i+1, letters);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<string>letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        string s;
        dfs(digits, s, ans, 0, letters);
        return ans;
    }
};