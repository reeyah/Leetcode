class Solution {
public:
    void rec(vector<vector<int>>&perm, int i, vector<int>&nums){
        if(i == nums.size()){
            perm.push_back(nums);
            return;
        }
        for(int j=i; j<nums.size();j++){
            swap(nums[i], nums[j]);
            rec(perm, i+1, nums);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perm;
        rec(perm, 0, nums);
        return perm;
    }
};