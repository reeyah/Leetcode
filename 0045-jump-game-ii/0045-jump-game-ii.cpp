class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), jumps = 0, maxFar = 0, curEnd = 0;

        for(int i=0; i<=n-1; i++) {
            if (curEnd == n-1)
                return jumps;
            /* Condition never occurs since TC says guaranteed to reach n-1 */
            if (i>curEnd) 
                return -1; 
            /* top lines skippable */

            maxFar = max(maxFar, i+nums[i]);
            if (i == curEnd) {
                jumps++;
                curEnd = min(maxFar, n-1);
            }
        }
        
        return jumps;
    }
};