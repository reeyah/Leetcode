class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), total =0, leftMax = 0, rightMax = 0;
        for(int i=0, j=n-1; i<j;){
            leftMax=max(leftMax, height[i]);
            rightMax=max(rightMax, height[j]);
            if(leftMax <= rightMax)
                total += leftMax-height[i++];  
            else total += rightMax-height[j--];
        }
        return total;
    }
};