class Solution {
public:
    // DFS
//     void markIslands(vector<vector<char>>& grid, int rows, int cols, int i, int j){
//         if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j] != '1')
//             return;
//         grid[i][j] = '2';
        
//         markIslands(grid, rows, cols, i-1, j);
//         markIslands(grid, rows, cols, i+1, j);
//         markIslands(grid, rows, cols, i, j-1);
//         markIslands(grid, rows, cols, i, j+1);
//     }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(),numOfIslands = 0, offsets[]={0,1,0,-1,0};
        if(rows == 0)
            return 0;
        
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                if(grid[i][j] == '1'){
                    // markIslands(grid, rows, cols, i, j);
                    numOfIslands++;
                    grid[i][j]='2';
                    queue<pair<int,int>>coords;
                    coords.push(make_pair(i,j));
                    while(!coords.empty()){
                        int x = coords.front().first, y = coords.front().second;
                        coords.pop();
                        for(int k=0; k<4; k++){
                            int r = x + offsets[k], c = y + offsets[k+1];
                            if(r>=0 && c>=0 && r<rows && c<cols && grid[r][c] == '1'){
                                grid[r][c]='2';
                                coords.push(make_pair(r,c));
                            }
                        }
                    }
                }
        return numOfIslands;
    }
};