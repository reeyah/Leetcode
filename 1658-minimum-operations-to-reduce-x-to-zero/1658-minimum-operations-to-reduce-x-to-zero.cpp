class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0) - x, curr=0, len=0;
		if(!sum)
            return nums.size();
        if(sum<0)
            return -1;

        for(int j=0, i=0; j<nums.size(); j++){
            curr+= nums[j];
            while(curr>sum && i<=j)
                curr-= nums[i++];
            if(curr==sum) 
                len = max(len, j-i+1);
        }
        return (len? nums.size()-len: -1); 
    }
};