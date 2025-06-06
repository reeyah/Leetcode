class Solution {
public:
    string robotWithString(string s) {
        vector<int>cnt(26, 0);
        for(char c: s)
            cnt[c-'a']++;
        int minCharacter = 0;
        stack<char> stk;
        string res;
        for (char c : s) {
            stk.emplace(c);
            cnt[c-'a']--;
            while (minCharacter != 25 && cnt[minCharacter] == 0) {
                minCharacter++;
            }
            while (!stk.empty() && stk.top()-'a' <= minCharacter) {
                res.push_back(stk.top());
                stk.pop();
            }
        }

        return res;
    }
};