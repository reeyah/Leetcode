class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int>dir(4, 0); //N,S,E,W;
        int north = 0, south = 0, east = 0, west = 0, res = 0;

        for(auto c: s) {
            if(c == 'N')
                north++;
            if(c == 'S')
                south++;
            if(c == 'W')
                west++;
            if(c == 'E')
                east++;

            int v = abs(north-south);
            int h = abs(east-west);

            int modV = min({north, south, k});
            int modH = min({west, east, k-modV});
            
            res = max(res, v + 2*modV + h + 2*modH);
        }

        return res;
    }
};