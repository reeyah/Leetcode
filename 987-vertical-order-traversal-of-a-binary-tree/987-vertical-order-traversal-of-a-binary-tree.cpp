/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> store;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode *curr = p.first;
            int x = p.second.first, y = p.second.second;
            store[x][y].insert(curr->val);
            if(curr->left)
                q.push({curr->left, {x-1, y+1}});
            if(curr->right)
                q.push({curr->right, {x+1, y+1}});
        }
        vector<vector<int>>res;
        for(auto i:store){
            res.push_back({});
            for(auto j:i.second)
                res.back().insert(res.back().end(), j.second.begin(), j.second.end());
        }
        return res;
    }
};