class Solution {
public:
    void rec(vector<vector<int>>&perm, int i, vector<int>nums){
        if(i==nums.size()-1){
            perm.push_back(nums);
            return;
        }
        for(int j=i; j<nums.size(); j++){
            if(i!=j && nums[i]==nums[j])
                continue;
            swap(nums[i], nums[j]);
            rec(perm, i+1, nums);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>perm;
        rec(perm, 0, nums);
        return perm;
    }
};