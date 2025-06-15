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
    unordered_map<TreeNode*, TreeNode*> parents;
    
    void makeParent(TreeNode* node) {
        if(node->left) {
            parents[node->left] = node;
            makeParent(node->left);
        }
        if(node->right) {
            parents[node->right] = node;
            makeParent(node->right);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;

        makeParent(root);

        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(target,0));
        visited.insert(target);

        while(!q.empty()) {
            auto [node, dist] = q.front();

            if(dist == k)
                break;
            
            q.pop();

            if (node->left && !visited.count(node->left)) {
                visited.insert(node->left);
                q.push({node->left, dist + 1});
            }

            if (node->right && !visited.count(node->right)) {
                visited.insert(node->right);
                q.push({node->right, dist + 1});
            }

            if (parents[node] && !visited.count(parents[node])) {
                visited.insert(parents[node]);
                q.push({parents[node], dist + 1});
            }
        }

        while(!q.empty()) {
            res.push_back(q.front().first->val);
            q.pop();
        }

        return res;
    }
};