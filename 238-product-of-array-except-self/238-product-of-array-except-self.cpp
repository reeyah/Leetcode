class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res, pre(n, 1), suff(n, 1);
        for(int i=1; i<n; i++){
            pre[i]=pre[i-1]*nums[i-1]; 
            suff[n-i-1]=suff[n-i]*nums[n-i];
        }
        for(int i=0; i<n; i++)
            res.push_back(pre[i]*suff[i]);
        return res;
    }
};