class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int r = nums[0], maxi = nums[0], mini = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]<0)
                swap(maxi, mini);               // 2 3 -2 4
            //cout<<maxi<<" ";
            maxi = max(nums[i], maxi*nums[i]);  // 3, 6 -> 6,   -2, -6 -> -2      4, -8-> 4
            mini = min(nums[i], mini*nums[i]);  // 3, 6 -> 3,   -2, -12, -> -12   4, -48 -> -48
            
            //cout<<maxi<<"\n";
            r = max(maxi, r);                   // 2, 6 -> 6    6, 2 -> 6       6, 8 -> 8
        }
        
        return r;
    }
};