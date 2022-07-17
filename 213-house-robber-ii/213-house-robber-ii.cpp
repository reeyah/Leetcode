class Solution {
public:
    int helpRob(vector<int>&nums){
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
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int>temp1, temp2;
        for(int i =0; i<nums.size(); i++){
            if(i!=nums.size()-1)
                temp2.push_back(nums[i]);
            if(i!=0)
                temp1.push_back(nums[i]);
        }
        return max(helpRob(temp1), helpRob(temp2));
    }
};