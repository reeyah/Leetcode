class Solution {
public:
    
    void recPerm(vector<int>nums, int i, vector<int>proc, vector<vector<int>>&power){
        if(i==nums.size()){
            power.push_back(proc);
            return;
        }
        int n = proc.size();
        for(int j = 0 ; j<= n; j++){
            vector<int> left, right;
            for(int k=0; k<j; k++)
                left.push_back(proc[k]);
            for(int k=j; k<n; k++)
                right.push_back(proc[k]);
            vector<int>temp = proc;
            proc = left;
            proc.push_back(nums[i]);
            proc.insert(proc.end(), right.begin(), right.end());
            recPerm(nums, i+1, proc, power);
            proc = temp;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>proc;
        vector<vector<int>>power;
        recPerm(nums, 0, proc, power);
        return power;
    }
};