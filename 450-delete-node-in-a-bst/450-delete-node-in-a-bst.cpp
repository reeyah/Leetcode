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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) root->left = deleteNode(root->left, key);     
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            else{ //condition key found
                if(!root->left && !root->right) 
                    return NULL;         
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;  
                // Both children exists
                TreeNode* temp = root->left;     // went to the left child of the node                   
                while(temp->right) temp = temp->right;  // traverse to right-most node of left child
                root->val = temp->val;                           
                root->left = deleteNode(root->left, temp->val); 		 //if that right-most child had a left child
            }
        return root;
    }
};