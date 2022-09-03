class Solution {
public:
    void dfs(vector<int>& nums, int i, vector<vector<int>>&subs, vector<int>&sub){
        if(i==nums.size()){
            subs.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        dfs(nums, i+1, subs, sub);
        sub.pop_back();
        dfs(nums, i+1, subs, sub);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subs;
        vector<int>sub;
        dfs(nums, 0, subs, sub);
        
        return subs;
    }
};