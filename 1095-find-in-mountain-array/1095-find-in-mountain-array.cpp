/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binary(int start, int end, MountainArray &mountainArr, int target){
        while(start<=end){
            int mid = start + (end-start)/2;
            if(mountainArr.get(mid)==target) 
                return mid;
            if(mountainArr.get(mid)>target)
                end = mid-1;
            else
                start = mid + 1;
        }
        
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start = 0, end = mountainArr.length()-1;
        while(start<end){
            int mid = start + (end-start)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1))
                end = mid;
            else start = mid + 1;
        }
        
        int peak = start;
        //cout<<peak;
        if(mountainArr.get(peak) == target) 
            return peak;
        start = 0, end = peak-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(mountainArr.get(mid)==target) 
                return mid;
            if(mountainArr.get(mid)>target)
                end = mid-1;
            else
                start = mid + 1;
        }
        start = peak+1, end = mountainArr.length()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(mountainArr.get(mid)==target) 
                return mid;
            if(mountainArr.get(mid)>target)
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }
};