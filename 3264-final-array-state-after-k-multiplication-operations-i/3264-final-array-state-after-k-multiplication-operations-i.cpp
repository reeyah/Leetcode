class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0; i<nums.size(); i++)
            pq.push(make_pair(nums[i],i));
        while(k--) {
            pair<int,int> curr = pq.top();
            pq.pop();
            nums[curr.second]*=multiplier;
            pq.push(make_pair(nums[curr.second],curr.second));
        }
        return nums;                                                                    
    }
};