class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] ={0}, col[9][9]={0}, cube[3][3][9]={0};
        for (int r = 0; r < 9; r++) 
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch != '.') {
                    if(row[r][ch - '1'] || col[c][ch - '1'] || cube[r/3][c/3][ch - '1'] ) 
                        return false;
                    row[r][ch - '1'] = 1;
                    col[c][ch - '1'] = 1;
                    cube[r/3][c/3][ch - '1'] = 1;
                }
            }
        return true;
    }
};