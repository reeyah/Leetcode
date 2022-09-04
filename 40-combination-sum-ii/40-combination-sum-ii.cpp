class Solution {
public:
        void rec(vector<vector<int>>&ans, vector<int>&s, vector<int>&candidates, int target, int i){
        if(target == 0){
            ans.push_back(s);
            return;
        }
        if(target < 0)
            return;
        for(int j=i; j<candidates.size() && target>=candidates[j]; j++){
            if(j!=i && candidates[j]==candidates[j-1])
                continue;
            s.push_back(candidates[j]);
            rec(ans, s, candidates, target - candidates[j], j+1);
            s.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>s;
        rec(ans, s, candidates, target, 0);
        return ans;
    }
};