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
    bool isSymmetricHelper(TreeNode* left, TreeNode* right){
        if(!left || !right)
            return left == right;
        if(left->val != right->val)
            return false;
        return isSymmetricHelper(left->left, right->right) &&
            isSymmetricHelper(right->left, left->right); 
    }
    
    bool isSymmetric(TreeNode* root) {
        return !root || isSymmetricHelper(root->left, root->right);
    }
};