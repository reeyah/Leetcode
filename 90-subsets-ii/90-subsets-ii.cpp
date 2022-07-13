class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> subs;
        subs.push_back({});
        for(int j = 0; j<nums.size(); j++){
            int start = 0, end;
            if(j>0 && nums[j] == nums[j-1])
                start = end;
            int n = subs.size();
            for(int i = start; i<n; i++){
                subs.push_back(subs[i]);
                subs.back().push_back(nums[j]);
            }
            end = n ; //gives the position where new number was added in the newly created array
        }
        
        return subs;
    }
};