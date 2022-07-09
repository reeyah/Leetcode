class Solution {
public:
    int binary(int start, int end, vector<int>nums, int target){
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, pivot=-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            cout<<mid<<" ";
            if(mid<end && nums[mid]>nums[mid+1]){
                pivot = mid;
                break;
            }
            // if(mid>start && nums[mid-1]>nums[mid]){
            //     pivot = mid-1;
            //     break;
            // }
            else if(nums[start]>nums[mid])
                end = mid;
            else start = mid + 1;
        }
        
        cout<<pivot;
        
        if(pivot==-1)
            return binary(0, nums.size()-1, nums, target);
        if(nums[pivot] == target) 
            return pivot;
        if(binary(0, pivot-1, nums, target) != -1)
            return binary(0, pivot-1, nums, target);
        if(binary(pivot+1, nums.size()-1, nums, target)!=-1)
            return binary(pivot+1, nums.size()-1, nums, target);
        return -1;
    }
};