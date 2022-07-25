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
    void preorderRev(TreeNode *root, int level, vector<int>&result){
        if(!root)
            return;
        if(level == result.size())
            result.push_back(root->val);
        preorderRev(root->right, level+1, result);
        preorderRev(root->left, level+1, result);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        preorderRev(root, 0, result);
        return result;
    }
};