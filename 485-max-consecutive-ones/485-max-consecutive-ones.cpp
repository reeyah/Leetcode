class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, m =0;
        for(auto num: nums){
            if(num==0)
                count = 0;
            else {
                count++;
                m = max(m, count);
            }
        }
        
        return m;
    }
};