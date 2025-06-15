class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, totalGas = 0, currentGas = 0;

        for (int i = 0; i < gas.size(); i++) {
            int fuelGain = gas[i] - cost[i];
            totalGas += fuelGain;
            currentGas += fuelGain;

            if (currentGas < 0) {
                currentGas = 0;
                start = i + 1;
            }
        }

        return totalGas < 0 ? -1 : start; 
    }
};