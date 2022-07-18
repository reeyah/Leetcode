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
    int kthSmallest(TreeNode* root, int& k ) {
        int n = -1;
        if(root){
            n = kthSmallest(root->left, k);
            if(k==0) {
                // cout<<n;
                return n;
            }
            k--;
            if(k==0){
                n = root->val;
                // cout<<n;
                return n;
            }
            return kthSmallest(root->right, k);
        }
       
        
        return n;
    }
};