class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
         for (int i = 0, x, y; ; ++i) {
            x = pq.top();
            pq.pop();
            if (x >= k) return i;
            y = pq.top();
            pq.pop();
            const long t = 2L * x + y; 
            pq.push(t < k ? (int)t : k);
        }
        return -1;
    }
};