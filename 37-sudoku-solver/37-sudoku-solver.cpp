class Solution {
        int row[9][9], col[9][9], cube[3][3][9];
public:
//     bool isSafe(vector<vector<char>>& board, int r, int c, char ch){
//         for(int i = 0; i<9; i++){
//             if(board[r][i] == ch) //row check
//                 return false;
//             if(board[i][c] == ch) //column check
//                 return false;
//                 if(board[r-r%3+i/3][c-c%3+i%3]==ch) //cube check
//                     return false;
//         }
        
//         return true;
//     }
     
    //Hash check - reduce complexity
    bool check(int r, int c, char ch) {
        if(row[r][ch - '1'] || col[c][ch - '1'] || cube[r/3][c/3][ch - '1'] ) 
            return false;
        return true;
    }
    
    bool isSolved(vector<vector<char>>& board, int r = 0, int c = 0){
        if(r==9) 
            return true;
        if(c==9)
            return isSolved(board, r+1, 0);
        if(board[r][c] != '.')
            return isSolved(board, r, c+1);
        for(char ch = '1'; ch<='9'; ch++){ //will try put every no. in every column
            if(check(r, c, ch)){
                board[r][c] = ch;
                row[r][ch - '1'] = 1; col[c][ch - '1'] = 1; cube[r/3][c/3][ch - '1'] = 1;
                if(isSolved(board, r, c+1))  //crucial check
                    return true;
                board[r][c] = '.';
                row[r][ch - '1'] = 0; col[c][ch - '1'] = 0; cube[r/3][c/3][ch - '1'] = 0;
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(cube, 0, sizeof(cube));
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    row[r][board[r][c] - '1'] = 1;
                    col[c][board[r][c] - '1'] = 1;
                    cube[r/3][c/3][board[r][c] - '1'] = 1;
                } 
            }
        }
        isSolved(board);
    }
};