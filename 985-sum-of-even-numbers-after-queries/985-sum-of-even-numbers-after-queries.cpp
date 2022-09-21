class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int sum = accumulate(begin(nums), end(nums), 0, [](int s, int a) { return s + (a % 2 == 0 ? a : 0); });
          for (auto &q : queries) {
            if (nums[q[1]] % 2 == 0) sum -= nums[q[1]];
            nums[q[1]] += q[0];
            if (nums[q[1]] % 2 == 0) sum += nums[q[1]];
            res.push_back(sum);
          }
          return res;
    }
};