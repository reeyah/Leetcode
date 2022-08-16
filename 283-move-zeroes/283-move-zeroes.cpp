class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i=0, j=0; i<n && j<n;j++){
            while(i<n && nums[i]!=0) i++; //until reaches a 0
            while(j<n && nums[j]==0) j++;
            if(j>=n || i>=n)
                return;
            cout<<nums[i]<<" "<<nums[j];
            if(i<j)
                swap(nums[i], nums[j]);
        }
        
    }
};