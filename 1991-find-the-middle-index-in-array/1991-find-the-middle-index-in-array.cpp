class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0, preSum =0;
        for(int num : nums) sum += num;
        
        for(int i=0; i<nums.size(); preSum += nums[i++])
            if(preSum * 2 == sum - nums[i])
                return i;
            
        return -1;
    }
};