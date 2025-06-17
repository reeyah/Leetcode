class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, right = 0, ans = 0;

        while (right < nums.size()) {
            // Maintain decreasing deque for max
            while (!maxDeque.empty() && nums[right] > maxDeque.back())
                maxDeque.pop_back();
            maxDeque.push_back(nums[right]);

            // Maintain increasing deque for min
            while (!minDeque.empty() && nums[right] < minDeque.back())
                minDeque.pop_back();
            minDeque.push_back(nums[right]);

            // Shrink window if invalid
            while (maxDeque.front() - minDeque.front() > limit) {
                if (nums[left] == maxDeque.front()) maxDeque.pop_front();
                if (nums[left] == minDeque.front()) minDeque.pop_front();
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};