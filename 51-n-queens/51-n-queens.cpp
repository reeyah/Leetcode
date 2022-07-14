class Solution {
public:
    bool isSafe(vector<string>&p, int n, int r, int c){
        for(int i = 0; i<r; i++) //vecrtical check
            if(p[i][c]=='Q')
                return false;
        
        int left = min(r, c);
        for(int i = 1; i<=left; i++) //left diagonal check
            if(p[r-i][c-i]=='Q')
                return false;
                
        int right = min(r, n-c-1);
        for(int i = 1; i<=right; i++) //right diagonal check
            if(p[r-i][c+i]=='Q')
                return false;
        
        return true;
        
    }
    
    void solveNQueens(vector<vector<string>>&res, vector<string>&p, int n, int r){
        if(r == n){
            res.push_back(p);
            return;
        }

        for(int c = 0; c<n; c++){
            if(isSafe(p, n, r, c)){
                p[r][c] = 'Q';
                solveNQueens(res, p, n, r+1);
                p[r][c] = '.';
            }
        }
    }
    // Observation 1 : vector<string> Each string represents one row.
    // The return vector contains all possibilities
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> res; // final answer
        vector<string> poss(n, string(n, '.')); //contains one possible arrangement
        solveNQueens(res, poss, n, 0);
        return res;
        // vector<vector<string> > res;
        // vector<string> nQueens(n, string(n, '.'));
        // vector<int> flag(5 * n - 2, 1);
        // solveNQueens(res, nQueens, flag, 0, n);
        // return res;
    }
    

// private:
//     void solveNQueens(vector<vector<string> > &res, vector<string> &nQueens, vector<int> &flag, int row, int &n) {
//         if (row == n) {
//             res.push_back(nQueens);
//             return;
//         }
//         for (int col = 0; col != n; ++col)
//             if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
//                 flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
//                 nQueens[row][col] = 'Q';
//                 solveNQueens(res, nQueens, flag, row + 1, n);
//                 nQueens[row][col] = '.';
//                 flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
//             }
//     }
};