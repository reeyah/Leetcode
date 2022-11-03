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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                bool isLeaf = true;
                if(cur->left){
                    q.push(cur->left);
                    isLeaf = false;
                }
                if(cur->right){
                    q.push(cur->right);
                    isLeaf = false;
                }
                if(isLeaf)
                    return depth+1; 
            }
            depth++;
        }
        return -1;
    }
};