class Solution {
public:
    //NOT GREEDY
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int prev1=0, prev2=0;
        for(auto num: nums){
            int curr = max(prev1, prev2+num);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};