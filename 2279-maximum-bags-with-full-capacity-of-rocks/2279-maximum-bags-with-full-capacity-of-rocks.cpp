class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i=0; i<capacity.size(); i++)
            capacity[i]-=rocks[i];
        sort(capacity.begin(), capacity.end());
        int i;
        for(i=0; i<capacity.size() && additionalRocks>=capacity[i]; i++)
            additionalRocks-=capacity[i];
        return i;
    }
};