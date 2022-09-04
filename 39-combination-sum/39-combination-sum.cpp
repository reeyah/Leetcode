class Solution {
public:
    void rec(vector<vector<int>>&ans, vector<int>&s, vector<int>&candidates, int target, int i){
        if(target == 0){
            ans.push_back(s);
            return;
        }
        if(target < 0)
            return;
        while(i<candidates.size() && target-candidates[i]>=0){
            s.push_back(candidates[i]);
            rec(ans, s, candidates, target - candidates[i], i);
            i++;
            s.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>s;
        rec(ans, s, candidates, target, 0);
        return ans;
    }
};