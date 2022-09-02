class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), path =0;
        if(!n || grid[0][0] || grid[n-1][n-1])
            return -1;
        queue<pair<int,int>>q;
        vector<vector<int>>dir = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
        q.push(make_pair(0,0));
        grid[0][0]=1;
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(x==n-1 && y==n-1)
                return grid[x][y];
            for(auto d: dir){
                int nx = x + d[0], ny = y + d[1];
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny] == 0){
                q.push(make_pair(nx,ny));
                grid[nx][ny] = grid[x][y] + 1;
                }
            }
        }
        
        return -1;
    }
};