class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>res(2);
        vector<int>count(nums.size());
        res[1] = 0;
        for(int i=0; i<nums.size(); i++){
            res[1] ^= (i+1)^nums[i];
            if(++count[nums[i]-1]==2)
                res[0] = nums[i];
        }
        res[1]^=res[0];
        return res;
    }
};