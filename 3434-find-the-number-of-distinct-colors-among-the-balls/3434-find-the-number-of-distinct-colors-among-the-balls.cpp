class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball, color;
        vector<int>results;

        for(auto &q: queries) {
            int b = q[0], c = q[1];
            if(ball.count(b)) 
                if(--color[ball[b]] == 0)
                    color.erase(ball[b]);
            ball[b] = c;
            color[c]++;
            results.push_back(color.size());
        }
        return results;
    }
};