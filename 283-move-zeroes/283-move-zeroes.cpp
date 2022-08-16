class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i=0, j=0;i<nums.size();i++){
	      if(nums[i]&&i==j)//skip nonzero elements
                j++;
            else if(nums[i]){
                nums[j++]=nums[i]; 
                nums[i]=0;
            }
        }
    }
};