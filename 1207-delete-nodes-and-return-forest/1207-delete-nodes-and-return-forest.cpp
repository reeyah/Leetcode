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
    TreeNode* solve(TreeNode* root, vector<TreeNode*>&res, unordered_set<int>&del) {
        if(!root)
            return root;
        
        root->left = solve(root->left, res, del);
        root->right = solve(root->right, res, del);

        if(del.find(root->val)!= del.end()) {
            if(root->left)
                res.push_back(root->left);
            if(root->right)
                res.push_back(root->right);
            return NULL;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del;
        for(auto d:to_delete)
            del.insert(d);

        vector<TreeNode*> res;

        solve(root, res, del);

        if(del.find(root->val) == del.end()) {
            res.push_back(root);
        }

        return res;
    }
};