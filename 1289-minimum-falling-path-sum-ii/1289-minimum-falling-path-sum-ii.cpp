class Solution {
public:
    // Different because we need to check every column except same in the next row
    //Could've solved with greedy if 'same coulmn' criteria wasn't there.
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<int>prev(grid.front());
        int m = grid.size(), n = grid[0].size();
        for(int i=1; i<m; i++){
            vector<int>temp(n);
            for(int j = 0; j<n; j++){
                int mini = 1e9;
                for(int k = 0; k<n; k++){
                    if(k==j)
                        continue;
                    int possMin = grid[i][j]+prev[k];
                    mini = min(mini,possMin);
                }
                
                temp[j]=mini;
            }
            prev = temp;
        }
        
        return *min_element(prev.begin(), prev.end());
    }
};