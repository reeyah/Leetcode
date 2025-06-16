class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;

        for(int i=0, j=i+1; j<nums.size() && i<j; j++) {
            while(nums[i] >= nums[j]) {
                i=j;
                if (++j >= nums.size()) 
                    break;
            }

            if (j >= nums.size()) 
                    break;

            cout<<nums[i]<<" "<<nums[j]<<endl;

            res = max(res, nums[j]-nums[i]);
        }

        return res;
    }
};