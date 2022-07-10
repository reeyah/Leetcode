class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>error;
        for(int i=0; i<nums.size(); ){
            if(nums[i]!=nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        
        for(int i = 0; i<nums.size(); i++)
            if(nums[i] != i+1){
                error.push_back(nums[i]);
                error.push_back(i+1);
            }
        return error;
    }
};