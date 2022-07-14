class Solution {
public:
    bool isSafe(vector<string> &pos, int r, int c, int n){
        for(int i = 0; i<r; i++)
            if(pos[i][c]=='Q')
                return false;
        
        int left = min(r, c);
        for(int i = 1; i<=left; i++) //left diagonal check
            if(pos[r-i][c-i]=='Q')
                return false;
                
        int right = min(r, n-c-1);
        for(int i = 1; i<=right; i++) //right diagonal check
            if(pos[r-i][c+i]=='Q')
                return false;
        return true;
    }
    
    int nQueens(vector<string> &pos, int r, int n){
        if(r==n)
            return 1;
        
        int count = 0;
        for(int c = 0; c<n ; c++){
            if(isSafe(pos, r, c, n)){
                pos[r][c] = 'Q';
                count+=nQueens (pos, r+1, n);
                pos[r][c] = '.';
            }
        }
        
        return count;
    }
    int totalNQueens(int n) {
        vector<string> pos(n, string(n, '.'));
        return nQueens (pos, 0, n);
    }
};