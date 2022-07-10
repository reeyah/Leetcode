class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), rStart = 0, cEnd = col-1, ans=0; 
        while(rStart < row && cEnd >=0){
            if( grid[rStart][cEnd] < 0){
                ans += row - rStart;
                cEnd--;
            }
            else rStart ++;
            
            //cout<<cEnd<<" "<<rStart<<"\n";
        }
        
        return ans;
    }
};