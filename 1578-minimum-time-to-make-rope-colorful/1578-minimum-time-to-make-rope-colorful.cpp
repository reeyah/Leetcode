class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0, maxTime = 0, n = colors.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && colors[i] != colors[i - 1])
                maxTime = 0;
            res += min(maxTime, neededTime[i]);
            maxTime = max(maxTime, neededTime[i]);
        }
        return res;        
    }
};