class Solution {
public:
    int helpRob(vector<int>&nums, int l, int r){
        if(nums.size()==0)
            return 0;
        int prev1=0, prev2=0;
        for(int i = l; i<=r; i++){
            int curr = max(prev1, prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return max(helpRob(nums, 0, nums.size()-2), helpRob(nums, 1, nums.size()-1));
    }
};