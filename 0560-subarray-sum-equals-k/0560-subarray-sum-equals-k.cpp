class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum =0;
        unordered_map<int,int>m;
        m[0]=1;
        for(auto num:nums){
            sum+=num;
            if(m.find(sum-k)!=m.end())
                count+=m[sum-k];
            m[sum]++;
        }
        return count;
    }
};