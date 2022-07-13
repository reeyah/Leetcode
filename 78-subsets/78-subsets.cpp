class Solution {
public:
//     vector<vector<int>>recSub(vector<int>nums, int i, vector<int>proc){
//         vector<vector<int>> power;
//         if(i==nums.size()){
//             power.push_back(proc);
//             return power;
//         }
//         int num = nums[i];
//         vector<vector<int>> left = recSub(nums, i+1, proc);
//         proc.push_back(num);
//         vector<vector<int>> right = recSub(nums, i+1, proc);
//         right.insert(right.end(), left.begin(), left.end());
        
//         return right;
//     }
    // void recSub(vector<int>nums, int i, vector<int>proc, vector<vector<int>>&power){
    //     if(i==nums.size()){
    //         power.push_back(proc);
    //         return;
    //     }
    //     proc.push_back(nums[i]);
    //     recSub(nums, i+1, proc, power);
    //     proc.pop_back();
    //     recSub(nums, i+1, proc, power);
    // }
    
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>proc;
        vector<vector<int>>power;
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
        
        //recSub(nums, 0, proc, power);
        subsets(nums, 0, proc, power);
        return power;
    }
};