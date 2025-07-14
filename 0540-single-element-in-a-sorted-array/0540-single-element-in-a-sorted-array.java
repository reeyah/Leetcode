class Solution {
    public int singleNonDuplicate(int[] nums) {
        int low = 0, high = nums.length - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Make sure mid is even
            if (mid % 2 == 1) {
                mid--;
            }

            // Check pair alignment
            if (nums[mid] == nums[mid + 1]) {
                // Single element is in right half
                low = mid + 2;
            } else {
                // Single element is in left half (including mid)
                high = mid;
            }
        }

        // low == high points to the single element
        return nums[low];
    }
}
