class Solution {
public:
    vector<vector<int>>recSub(vector<int>nums, int i, vector<int>proc){
        vector<vector<int>> power;
        if(i==nums.size()){
            power.push_back(proc);
            return power;
        }
        int num = nums[i];
        vector<vector<int>> left = recSub(nums, i+1, proc);
        proc.push_back(num);
        vector<vector<int>> right = recSub(nums, i+1, proc);
        right.insert(right.end(), left.begin(), left.end());
        
        return right;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int i = 0;
        vector<int>proc;
        // int n = nums.size(), p = 1 << n;
        // vector<vector<int>> subs(p);
        // for (int i = 0; i < p; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if ((i >> j) & 1) {
        //             subs[i].push_back(nums[j]);
        //         }
        //     }
        // }
        // return subs;
        
        return recSub(nums, i, proc);
    }
};