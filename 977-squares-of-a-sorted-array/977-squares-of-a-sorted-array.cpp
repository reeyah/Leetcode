class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        for(int i=0, j=n-1, k=n-1; i<=j;k--){
            if(abs(nums[i])>abs(nums[j]))
                res[k] = nums[i]*nums[i++];
            else res[k] = nums[j]*nums[j--];
        }
        return res;
    }
};