class Solution {
public:
    void markIslands(vector<vector<char>>& grid, int rows, int cols, int i, int j){
        if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j] != '1')
            return;
        grid[i][j] = '2';
        
        markIslands(grid, rows, cols, i-1, j);
        markIslands(grid, rows, cols, i+1, j);
        markIslands(grid, rows, cols, i, j-1);
        markIslands(grid, rows, cols, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if(rows == 0)
            return 0;
        
        int numOfIslands = 0;
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                if(grid[i][j] == '1'){
                    markIslands(grid, rows, cols, i, j);
                    numOfIslands++;
                }
        return numOfIslands;
    }
};