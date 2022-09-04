class Solution {
public:
    void rec(vector<vector<int>>&perm, int i, vector<int>&nums){
        if(i==nums.size()){
            perm.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int j=i; j<nums.size(); j++){
            // if(i!=j && nums[i]==nums[j])
            if(s.find(nums[j])!=s.end())
                continue;
            s.insert(nums[j]);
            swap(nums[i], nums[j]);
            rec(perm, i+1, nums);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>perm;
        rec(perm, 0, nums);
        return perm;
    }
};