class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), jumps = 0, maxFar = 0, curEnd = 0;

        for(int i=0; i<n-1; i++) {
            /* Condition never occurs since nums[i] >= 0 and hence jump always possible */
            if (i>curEnd) 
                return -1; 
            /* top lines skippable */

            maxFar = max(maxFar, i+nums[i]);
            if (i == curEnd) {
                jumps++;
                curEnd = min(maxFar, n-1);
            }

            if (curEnd == n-1)
                return jumps;
        }
        
        return 0;
    }
};