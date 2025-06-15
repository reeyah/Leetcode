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
    // HAS A CAMERA --> 2
    // COVERED BY A CAMERA --> 1
    // NO CAMERA --> 0
    int dfs(TreeNode* root, int &cam){
        if(root == NULL)
            return 1;
        int left = dfs(root->left, cam);
        int right = dfs(root->right, cam);
        
        if(left == 0 || right == 0){
            cam++;
            return 2;
        }
        
        if(left == 2 || right == 2)
            return 1;
        
        else return 0;
            
    }
    int minCameraCover(TreeNode* root) {
        int cam = 0;
        return dfs(root, cam)? cam : cam+1;
    }
};