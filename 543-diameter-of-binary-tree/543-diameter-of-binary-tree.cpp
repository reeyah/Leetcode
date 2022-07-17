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
    int dfsHeight(TreeNode* root, int *diameter){
        if(!root)
            return 0;
        int lh = dfsHeight(root->left, diameter);
        int rh = dfsHeight(root->right, diameter);
        
        *diameter = max(*diameter, lh+rh);
        
        return max(lh, rh)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfsHeight(root, &diameter);
        return diameter;
    }
};