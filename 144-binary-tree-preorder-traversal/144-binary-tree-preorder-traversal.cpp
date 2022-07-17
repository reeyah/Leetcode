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
    // vector<int>pre;
    vector<int> preorderTraversal(TreeNode* root) {
//         if(root == NULL)
//             return pre;
//         pre.push_back(root->val);
//         preorderTraversal(root->left);
//         preorderTraversal(root->right);
        
//         return pre;
        
        vector<int>pre;
        if(root == NULL)
            return pre;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            pre.push_back(node->val);
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);
        }
        
        return pre;
    }
};