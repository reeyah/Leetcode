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
class BSTIterator {
private:
    stack<TreeNode*> Stack;
    TreeNode* node;
    bool forward;
public:
    BSTIterator(TreeNode* root, bool isForward){
        node = root;
        forward = isForward;
    }
    
    int next(){
        while(node){
            Stack.push(node);
            node = forward ? node->left : node->right;
        }
        TreeNode* cur = Stack.top(); Stack.pop();
        node = forward ? cur->right : cur ->left;
        return cur->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator leftItr(root, true), rightItr(root, false);
        int left = leftItr.next(), right = rightItr.next();
        while (left < right) {
            if (left + right == k) return true;
            if (left + right < k)
                left = leftItr.next();
            else
                right = rightItr.next();
        }
        return false;
    }
};