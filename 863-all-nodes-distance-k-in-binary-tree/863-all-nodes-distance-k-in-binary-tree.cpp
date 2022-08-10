/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* node, unordered_map<TreeNode*, TreeNode*>&parents){
        if( node->left ){
            parents[node->left] = node;
            markParents(node->left, parents);
        }
        if( node->right){
            parents[node->right] = node;
            markParents(node->right, parents);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parents;
        markParents(root, parents);
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]= true;
        int level = 0;
        while(!q.empty()){
            //cout<<level<<" ";
            int size = q.size();
            if(level++ == k)
                break;
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]= true;                    
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]= true;                    
                }
                if(parents[node] && !vis[parents[node]]){
                    q.push(parents[node]);
                    vis[parents[node]]= true;
                }
            }
        }
        
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        
        return res;
    }
};