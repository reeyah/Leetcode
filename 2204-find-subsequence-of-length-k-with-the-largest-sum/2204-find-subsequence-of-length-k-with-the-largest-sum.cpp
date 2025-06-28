class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if (k==nums.size())
            return nums;
        
        vector<int> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_set<int>idx;

        for(int i=0; i<nums.size(); i++) {
            if(pq.size() == k && (nums[i] > pq.top().first)) {
                pq.pop();
                pq.push({nums[i], i});
            }
            if(pq.size() < k)
                pq.push({nums[i], i});
        }

        while(!pq.empty()) {
            idx.insert(pq.top().second);
            pq.pop();
        }

        for(int i=0; i<nums.size(); i++) {
            if(idx.count(i))
                res.push_back(nums[i]);
        }

        return res;
    }
};