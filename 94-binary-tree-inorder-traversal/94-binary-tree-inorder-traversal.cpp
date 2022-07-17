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
    vector<int>in;
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>in;
        if(root == NULL)
            return in;
        // inorderTraversal(root ->left);
        // in.push_back(root->val);
        // inorderTraversal(root->right);
        TreeNode* node = root;
        stack<TreeNode*> s;
        while(true){
            if(node!=NULL){
                s.push(node);
                node = node->left;
            }else {
                if(s.empty())
                    break;
                node = s.top();
                s.pop();
                in.push_back(node->val);
                node=node->right;
            }
        }
        
        return in;
    }
};