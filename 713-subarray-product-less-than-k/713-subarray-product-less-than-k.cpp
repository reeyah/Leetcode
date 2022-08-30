class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)
            return 0;
        long prod=1,count=0;
        for(int i=0, j=0; i<nums.size();i++){
            prod *= nums[i];
            while(j<=i && prod >=k)
                prod /= nums[j++];
            count += i-j+1;
        }
        return count;
    }
};