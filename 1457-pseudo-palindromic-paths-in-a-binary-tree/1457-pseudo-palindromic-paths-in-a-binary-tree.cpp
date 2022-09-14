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
    int solve(TreeNode*root, unordered_set<int>&h){
        if(!root)
            return 0;
        bool erased = false;
        if(h.find(root->val) != h.end()){
            h.erase(root->val);
            erased = true;
        }
        else h.insert(root->val);
        if(!root->left && !root->right){
            int ans = h.size()<=1 ? 1:0;
            if(erased)
                h.insert(root->val);
            else h.erase(root->val);
            return ans;
        }
        
        int left = solve(root->left, h);
        int right = solve(root->right, h);
        if(erased) // backtracking
            h.insert(root->val);
        else h.erase(root->val);
        return left + right;
    }
    int pseudoPalindromicPaths (TreeNode* root, int count=0) {
        if(!root)
            return 0;
        unordered_set<int>h;
        return solve(root, h);
    }
};