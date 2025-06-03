class Solution {
private:
    int dfs(vector<vector<int>>&grid, vector<vector<bool>>&visited, int r, int c) {
        int rows = grid.size(), cols = grid[0].size(), area=1;
        vector<int> dir = {-1,0,1,0,-1};
        if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || !grid[r][c])
            return 0;
        
        visited[r][c] = true;
        for(int i=0; i<4; i++) {
            area += dfs(grid, visited, r+dir[i], c+dir[i+1]);
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0, rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(grid[r][c] && !visited[r][c]) {
                    area = max(area, dfs(grid, visited, r, c));
                } 
            }
        }
        return area;
    }
};