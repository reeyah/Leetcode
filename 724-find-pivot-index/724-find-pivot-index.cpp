class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tSum = accumulate(nums.begin(), nums.end(), 0);
        int pSum = 0;
        for(int i=0; i<nums.size(); i++){
            if(pSum * 2 == tSum-nums[i])
                return i;
            pSum += nums[i];
        }
        return -1;
    }
};