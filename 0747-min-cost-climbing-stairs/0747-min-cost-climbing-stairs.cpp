class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // cost.push_back(0);
        int prevCost = cost[1], prevCost2 = cost[0], currCost;
        
        for(int i=2; i<cost.size(); i++) {
            currCost = cost[i] + min(prevCost, prevCost2);
            prevCost2 = prevCost;
            prevCost = currCost;
        }

        return min(prevCost, prevCost2);
    }
};