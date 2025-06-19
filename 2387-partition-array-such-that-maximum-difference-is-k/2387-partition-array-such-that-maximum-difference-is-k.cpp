class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, localMin = nums[0];

        for(int i=1; i<nums.size(); i++) {
            if(nums[i]-localMin > k) {
                ans++;
                localMin = nums[i];
            }
        }

        return ans;
    }
};