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
private:
    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode *first = NULL , *second = NULL;
public:
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        if(!first && prev->val>root->val)
            first = prev;
        if(first && prev->val>root->val)
            second = root;
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};