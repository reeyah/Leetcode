class Solution {
public:
    vector<int>dir = {0,1,0,-1,0};
    bool isWord(vector<vector<char>>& board, string& word, int i, int j){
        int m = board.size(), n = board[0].size();
        if(word.size()==0)
            return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[0])
            return false;
        char ch = board[i][j];
        board[i][j]='0';
        
        string s = word.substr(1);
        for(int k=0; k<4; k++){
            if(isWord(board, s, i+dir[k], j+dir[k+1]))
                return true;
        }
        board[i][j]=ch;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                if(isWord(board, word, i, j))
                    return true;
        return false;
    }
};