class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(hash.find(target - nums[i]) != hash.end()){
                return {hash[target-nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};