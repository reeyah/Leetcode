class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i = 0; i<nums.size();){
            if(nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        
        vector<int>duplicates;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1)
                 duplicates.push_back(nums[i]);
        }
        
        return duplicates;
    }
};