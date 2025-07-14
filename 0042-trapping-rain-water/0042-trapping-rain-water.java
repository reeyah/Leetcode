class Solution {
    public int trap(int[] height) {
        int left = 0, right = height.length - 1;
        int leftMax = 0, rightMax = 0;
        int trapped = 0;

        while (left < right) {
            // Choose the smaller boundary to process
            if (height[left] < height[right]) {
                // Update left max
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    // Water trapped = leftMax - height
                    trapped += leftMax - height[left];
                }
                left++; // Move inward
            } else {
                // Update right max
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    // Water trapped = rightMax - height
                    trapped += rightMax - height[right];
                }
                right--; // Move inward
            }
        }

        return trapped;
    }
}
