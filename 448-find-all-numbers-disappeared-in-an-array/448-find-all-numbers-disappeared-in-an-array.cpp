class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i<nums.size();){
            if(nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        vector<int>missing;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1)
            missing.push_back(i+1);
        }
        
        return missing;
    }
    
};