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
    void dfs(TreeNode* root, int &count, int high){
        if(!root)
            return;
        if(root->val >= high){
            count++;
            high = root->val;
        }
        
        dfs(root->left, count, high);
        dfs(root->right, count, high);   
    }
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        int count = 0;
        dfs(root, count, root->val);
        return count;
    }
};