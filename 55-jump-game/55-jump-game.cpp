class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0, n=nums.size();
        for (int i = 0; i < n && i <= reach; ++i)
            reach = max(i + nums[i], reach);
        return reach >= n-1;
    }
};