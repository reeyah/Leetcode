class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            nums[i]+=nums[i-1];
        }
        for(auto &q:queries)
            ans.push_back(upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        return ans;
    }
};