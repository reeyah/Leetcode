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
        return !node->left &&!node->right;
    }
    
    TreeNode* dfs(TreeNode* node){
        if(!node)
            return NULL;
        node->left = dfs(node->left);
        node->right = dfs(node->right);
        if(isLeaf(node) && node->val==0)
            node = NULL;
        return node;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return root;
        root = dfs(root);
        return root;
    }
};