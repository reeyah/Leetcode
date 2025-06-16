class Solution {
private:
    int dist(vector<int> &ptA, vector<int> &ptB) {
        return abs(ptA[0]-ptB[0]) + abs(ptA[1]-ptB[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool>visited(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq; //min heap

        int distance = 0;

        pq.push({0, 0});

        while(!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();

            if(visited[u])
                continue;
            
            visited[u] = true;
            distance += w;

            for(int v = 0; v < n ; v++) {
                if(!visited[v]) {
                    int d = dist(points[u], points[v]);
                    pq.push({d, v});
                }
            }
        }

        return distance;
    }
};