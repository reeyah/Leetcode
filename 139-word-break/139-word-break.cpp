class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        queue<int> todo;
        unordered_set<int> visited;
        todo.push(0);
        while (!todo.empty()) {
            int i = todo.front();
            todo.pop();
            if (visited.find(i) == visited.end()) {
                visited.insert(i);
                for (string word : wordDict) {
                    int m = word.size();
                    if (i + m <= n && s.substr(i, m) == word) {
                        if (i + m == n) {
                            return true;
                        }
                        todo.push(i + m);
                    }
                }
            }
        }
        return false;
    }
};