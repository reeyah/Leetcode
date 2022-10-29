class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>pg;
        for(int i=0; i<plantTime.size();i++)
            pg.push_back(make_pair(growTime[i], plantTime[i]));
        sort(pg.begin(), pg.end());
        int res = 0;
        for(auto [g, p]:pg)
            res = max(res, g)+p;
        return res;
    }
};