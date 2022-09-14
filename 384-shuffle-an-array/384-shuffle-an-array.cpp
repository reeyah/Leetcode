class Solution {
    vector<int>original;
    int n;
public:
    Solution(vector<int>& nums) {
        original = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int>shuffled = original;
        //srand(time(NULL));
        for(int i=0; i<original.size(); i++){
            int j = rand()%(i+1);
            swap(shuffled[i], shuffled[j]);
        }
        
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */