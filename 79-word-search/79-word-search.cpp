class Solution {
public:
    vector<int>dir = {0,1,0,-1,0};
    bool isWord(vector<vector<char>>& board, string&word, int i, int j, string &s, int ind){
        int m = board.size(), n = board[0].size();
        if(word == s)
            return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[ind])
            return false;
        char ch = board[i][j];
        board[i][j]='0';
        s+=ch;
        for(int k=0; k<4; k++){
            if(isWord(board, word, i+dir[k], j+dir[k+1],s,ind+1))
                return true;
        }
        board[i][j]=ch;
        s.pop_back();
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        string s;
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                if(isWord(board, word, i, j, s, 0))
                    return true;
        return false;
    }
};