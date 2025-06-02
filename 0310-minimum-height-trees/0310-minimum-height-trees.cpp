class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0};

        vector<vector<int>> graph(n);
        vector<int> degree(n,0);
        for (auto e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(degree[i]==1)
                q.push(i);
        }
        vector<int>res;
        while(!q.empty()) {
            res.clear();
            int size = q.size();
            for(int i=0; i<size; i++){
                int cur = q.front();
                q.pop();
                res.push_back(cur);

                for(auto neighbor: graph[cur]) {
                    degree[neighbor]--;
                    if(degree[neighbor]==1)
                        q.push(neighbor);
                }
            }
        }

        return res;

    }
};