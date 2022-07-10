class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), rStart = 0, cEnd = col-1, ans=0; 
        while(rStart < row){
            while(cEnd >=0 && grid[rStart][cEnd] < 0)
                cEnd--;
            ans += col - (cEnd + 1);
            rStart ++;
        }
        
        return ans;
    }
};