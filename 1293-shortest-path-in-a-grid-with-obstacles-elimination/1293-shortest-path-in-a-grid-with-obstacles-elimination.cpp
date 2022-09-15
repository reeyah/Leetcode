class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n =grid[0].size(), steps=1, shortest=m+n-2;
        if(k>=shortest-1)
            return shortest;
        vector<int>dir = {0,1,0,-1,0};
        vector<vector<int>>vis(m, vector<int>(n,-1));
        queue<vector<int>>q;
        q.push({0,0,k});
        vis[0][0]=k;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto v = q.front(); q.pop();
                int x = v[0], y=v[1], left=v[2];
                if(vis[x][y]>left)
                    continue;
                for(int k=0; k<4; k++){
                    int x1 = x+dir[k], y1=y+dir[k+1], newLeft = left;
                    if(x1==m-1 && y1==n-1)
                        return steps;
                    if(x1<0 || y1<0 || x1>=m || y1>=n)
                        continue;
                    if(grid[x1][y1])
                        newLeft--;
                    if(vis[x1][y1]>=newLeft)
                        continue;
                    else vis[x1][y1] = newLeft;
                    int dist = m-x1 + n-y1 -2;
                    if(dist-1<=newLeft && dist == shortest-1)
                        return steps+dist;
                    shortest = min(shortest, dist);
                    q.push({x1, y1, newLeft});
                }       
            }
            steps++;
        }
        return -1;
    }
};