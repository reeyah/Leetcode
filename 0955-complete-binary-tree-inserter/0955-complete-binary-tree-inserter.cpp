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
class CBTInserter {
private:
    vector<TreeNode*>tree;
public:
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for(int i = 0; i<tree.size(); i++) {
            if(tree[i]->left)
                tree.push_back(tree[i]->left);
            if(tree[i]->right)
                tree.push_back(tree[i]->right);
        }
    }
    
    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        tree.push_back(node);

        int n = tree.size(); // after inserting
        if(n%2) {
            tree[(n-2)/2]->right = node;
            return tree[(n-2)/2]->val;
        }
        tree[(n-1)/2]->left = node;
        return tree[(n-1)/2]->val;
    }
    
    TreeNode* get_root() {
        return tree[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */