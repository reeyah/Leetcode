class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);

        // no node can have indegree more than 1 (>1 parent)
        for(int i=0; i<n; i++) {
            if(leftChild[i] != -1)
                if(++indegree[leftChild[i]] > 1)
                    return false;
            if(rightChild[i] != -1)
                if(++indegree[rightChild[i]] > 1)
                    return false;
        }

        int root = -1;
        // root identifcation
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                if(root != -1)
                    return false; //already found root, disconnected
                root = i;
            }
        }

        if (root == -1)
            return false;
        
        // BFS: needed bc case can be of a single root and a disconnected cycle

        vector<bool>visited(n, false);
        queue<int>q;
        q.push(root);
        int count = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto child : {leftChild[node], rightChild[node]}) {
                if(child != -1) {
                    if(visited[child])
                        return false;
                    q.push(child);
                    visited[child] = true;
                    count++;
                }
            }
        }

        return count == n;
    }
};