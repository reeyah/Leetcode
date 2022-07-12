class Solution {
public:
    int BS(vector<int>& nums, int target, int s, int e){
        if(s>e)
            return -1;
        int mid = s + (e - s)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] > target)
            return BS(nums, target, s, mid - 1);
        return BS(nums, target, mid+1, e);
    }
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
//         while( start <= end ){
//             int mid = start + (end - start)/2;
//             //cout<<mid;
//             if(nums[mid]==target)
//                 return mid;
//             if(nums[mid]>target)
//                 end = mid-1;
//             else start = mid+1;
//         }
        
//         return -1;
        return BS(nums, target, start, end);
    }
};