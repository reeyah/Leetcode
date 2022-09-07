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
    void append(TreeNode* node, string &s){
        if(!node)
            return;
        
        s+=to_string(node->val);
        if(node->left){
            s+="(";
            append(node->left, s);
            s+=")";
        }
        else if(node->right)
            s+="()";
        if(node->right){
            s+="(";
            append(node->right, s);
            s+=")";
        }
    }
    string tree2str(TreeNode* root) {
        string s;
        if(!root)
            return s;
        append(root, s);
        return s;
    }
};