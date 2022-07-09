class Solution {
public:
    int pivotIndex(vector<int>& nums) {
//         int sumLeft = 0, sumRight = 0, i=0, j = nums.size()-1;
//         while(i<j){
//             if(sumLeft == sumRight){
//                 sumLeft+= nums[i++];
//                 sumRight+= nums[j--];
//             }
            
//             else if(sumLeft > sumRight)
//                 sumRight += nums[j--];
//             else sumLeft += nums[i++];
//         }
        
//         if(sumLeft == sumRight)
//             return i;
//         return -1;
        
        int sum = 0, preSum =0;
        for(int num : nums) sum += num;
        
        for(int i=0; i<nums.size(); preSum += nums[i++])
            if(preSum * 2 == sum - nums[i])
                return i;
            
        return -1;
    }
};