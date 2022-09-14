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
    int solve(TreeNode*root, map<int, int>&mp){
        if(!root)
            return 0;
        mp[root->val]++;
        if(!root->left && !root->right){
            int odd = 0;
            for(auto m:mp){
                if(m.second&1)
                    odd++;
            }
            mp[root->val]--;
            return odd<=1? 1:0;
        }
        
        int left = solve(root->left, mp);
        int right = solve(root->right, mp);
        mp[root->val]--;
        return left + right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)
            return 0;
        map<int, int>mp;
        return solve(root, mp);
    }
};