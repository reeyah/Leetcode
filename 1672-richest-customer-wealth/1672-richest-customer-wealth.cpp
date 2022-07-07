class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int num_row = accounts.size(); 
        int num_col = accounts[0].size();
        int maximum = 0; 
        for(int i=0;i<num_row;i++){
            int sum =0;
            for(int j=0;j<num_col;j++){
                sum += accounts[i][j];
            }
            maximum = max(maximum,sum);
        }
        return maximum;
    }
};