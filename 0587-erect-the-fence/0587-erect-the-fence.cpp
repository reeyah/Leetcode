class Solution {
    static bool mycompare(vector<int>& a, vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    
    int orientation(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b[0] - a[0])*(c[1] - b[1]) - (b[1] - a[1])*(c[0] - b[0]);
    }
    
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if(n<=3)
            return trees;
        vector<vector<int>> ans;
        sort(trees.begin(), trees.end(), mycompare);
        for (int i = 0; i < n; ++i) {
            while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), trees[i]) < 0) 
                ans.pop_back();
            ans.push_back(trees[i]);
        }

        if (ans.size() == n) 
            return ans;
        for (int i = n-2; i >= 0; --i) {
            while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), trees[i]) < 0) 
                ans.pop_back();
            ans.push_back(trees[i]);
        }
        ans.pop_back();
        return ans;
    }
};