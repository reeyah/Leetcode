class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir = {0,1,0,-1,0};
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(grid[i][j]==2)
                    q.push({i, j});
                if(grid[i][j]==1)
                    fresh++;
            }
        if(fresh==0)
            return 0;
        int t=-1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto p = q.front(); q.pop();
                for(int k=0; k<4; k++){
                    int x = p.first + dir[k];
                    int y = p.second + dir[k+1];
                    
                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x, y});
                        fresh--;
                    }
                }
            }
            t++;
        }
        
        return fresh>0? -1:t;
    }
};