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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int>hashIn;
        for(int i = 0; i<inorder.size(); i++)
            hashIn[inorder[i]] = i;
        int rootIdx = postorder.size()-1;
        return build(postorder, inorder, rootIdx, 0, inorder.size()-1, hashIn);
    }
    
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int &rootIdx, int left, int right, unordered_map<int, int>&hashIn) {
        if (left > right) return NULL;
        int pivot = hashIn[postorder[rootIdx]];
        
        rootIdx--;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->right = build(postorder, inorder, rootIdx, pivot+1, right, hashIn);
        newNode->left = build(postorder, inorder, rootIdx, left, pivot-1, hashIn);
        return newNode;
    }
};