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
    int dfs(TreeNode* node, int& maxSum){
        if(node == NULL)
            return 0;
        
        int leftSum = max(0,dfs(node->left, maxSum));
        int rightSum = max(0,dfs(node->right, maxSum));
        
        maxSum = max((node->val + leftSum + rightSum),maxSum);
        
        return node->val + max(leftSum, rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum = -1e5;
        dfs(root, maxSum);
        return maxSum;
    }
};