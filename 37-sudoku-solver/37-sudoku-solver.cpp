class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, char ch){
        for(int i = 0; i<9; i++){
            if(board[r][i] == ch) //row check
                return false;
            if(board[i][c] == ch) //column check
                return false;
                if(board[r-r%3+i/3][c-c%3+i%3]==ch) //cube check
                    return false;
        }
        
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
            if(isSafe(board, r, c, ch)){
                board[r][c] = ch;
                if(isSolved(board, r, c+1)) 
                    return true;
                board[r][c] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        isSolved(board);
    }
};