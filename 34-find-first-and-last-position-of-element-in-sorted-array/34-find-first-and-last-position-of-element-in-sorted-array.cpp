class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int it1 = std::lower_bound(nums.begin(), nums.end(), target)  - nums.begin();
        int it2 = std::upper_bound(nums.begin(), nums.end(), target)  - nums.begin();
        //cout<<it2;
        if (it1<=it2 && it1 < nums.size() && nums[it1] == target) 
            return {it1, it2-1};
        return {-1, -1};
    }
};