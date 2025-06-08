class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // not needed due to constraints
        if(cost.size() == 1)
            return cost[0];
        if(cost.size() == 2)
            return min(cost[0], cost[1]);

        int prevCost = cost[1], prevCost2 = cost[0], currCost;
        
        for(int i=2; i<cost.size(); i++) {
            currCost = cost[i] + min(prevCost, prevCost2);
            prevCost2 = prevCost;
            prevCost = currCost;
        }

        return min(prevCost, prevCost2);
    }
};