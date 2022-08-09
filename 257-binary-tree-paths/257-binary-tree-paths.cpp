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
    bool isLeaf(TreeNode* node){
        return !node->left && !node->right;
    }
    
    void helper(TreeNode* root, vector<string>&res, string s){

        if(isLeaf(root)){
            res.push_back(s);
            return;
        }
        if(root->left)helper(root->left, res, s+"->"+to_string(root->left->val));
        if(root->right)helper(root->right, res, s+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        if(root==NULL)
            return result;
        string s = to_string(root->val);
        helper(root, result, s);

        return result;
    }
};