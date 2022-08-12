class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows=grid.size(), cols=grid[0].size();
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> q;
        
        q.push({0,0,0,k});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it[0], y = it[1];
            
            if(x==rows-1 && y ==cols-1)
                return it[2];
            
            if(x<0 || y<0 || x>=rows || y>=cols)
                continue;
            
            if(grid[x][y]==1){
                if(it[3]>0)
                    it[3]--;
                else continue;
            }
            
            if(vis[x][y]!=-1 && vis[x][y]>=it[3])
                continue;
            vis[x][y] = it[3];
            
            q.push({x+1, y, it[2]+1, it[3]});
            q.push({x-1, y, it[2]+1, it[3]});
            q.push({x, y+1, it[2]+1, it[3]});
            q.push({x, y-1, it[2]+1, it[3]});
        }
        
        return -1;
    }
};