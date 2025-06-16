class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;

        for(int i=0, j=i+1; j<nums.size() && i<j; j++) {
            if(nums[i] >= nums[j]) 
                i=j;
            else 
                res = max(res, nums[j]-nums[i]);   
        }
        return res;
    }
};