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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>hashIn;
        for(int i = 0; i<inorder.size(); i++)
            hashIn[inorder[i]] = i;
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1, hashIn);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &rootIdx, int left, int right, unordered_map<int, int>&hashIn) {
        if (left > right) return NULL;
        int pivot = hashIn[preorder[rootIdx]];
        
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, rootIdx, left, pivot-1,hashIn);
        newNode->right = build(preorder, inorder, rootIdx, pivot+1, right,hashIn);
        return newNode;
    }
};