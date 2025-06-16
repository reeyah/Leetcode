class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int ptA, int ptB) {
        int x = find(ptA);
        int y = find(ptB);

        if(x==y)
            return false; //pts A, B already connected
        
        if(rank[x] > rank[y])
            parent[y] = x;
        
        else if(rank[y] > rank[x])
            parent[x] = y;

        else {
            parent[y] = x;
            rank[x]++;
        }

        return true;
    }
};

class Solution {
private:
    int dist(vector<int> &ptA, vector<int> &ptB) {
        return abs(ptA[0]-ptB[0]) + abs(ptA[1]-ptB[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>graph;

        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                graph.push_back({i, j, dist(points[i], points[j])}); 
            }
        }

        DSU dsu(points.size());
        int distance = 0, count=0;

        sort(graph.begin(), graph.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        // for(auto g:graph) {
        //     cout<<g[0]<<" "<<g[1]<<" "<<g[2]<<endl;
        // }

        for(auto g: graph) {
            if(dsu.Union(g[0], g[1])) {
                distance += g[2];
                count++;
            }
            if(count == points.size()-1)
                break;
        }

        return count == points.size()-1 ? distance : -1;
    }
};