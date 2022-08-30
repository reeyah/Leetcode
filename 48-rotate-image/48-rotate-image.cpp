class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> res(n, vector<int>(n));
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                res[i][j] = matrix[n-1-j][i];
            }
        }
        matrix = res;
    }
};