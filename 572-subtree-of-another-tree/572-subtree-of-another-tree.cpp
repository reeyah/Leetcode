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
    vector<TreeNode*> nodes;
    int subVal;
    bool isIdentical (TreeNode* root1, TreeNode* root2){
        if(root1 == NULL || root2 == NULL)
            return root1 == root2;
        
        return root1->val == root2->val && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
    
    int getDepth(TreeNode* r, int d) {
        if (!r)
            return -1;

        int depth = max(getDepth(r->left, d), getDepth(r->right, d)) + 1;
        if (depth == d && r->val == subVal)
            nodes.push_back(r);

        return depth;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        subVal = subRoot->val;
        getDepth(root, getDepth(subRoot, -1));

        for (TreeNode* n: nodes)
            if (isIdentical(n, subRoot))
                return true;

        return false;
    }
};