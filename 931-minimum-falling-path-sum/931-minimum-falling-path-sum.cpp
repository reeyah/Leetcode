class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int>prev(matrix.front());
        int m = matrix.size(), n = matrix[0].size();
        for(int i=1; i<m; i++){
            vector<int>temp(n);
            for(int j = 0; j<n; j++){
                int p = 1e9, c = 1e9, next = 1e9;
                c = matrix[i][j] + prev[j];
                if(j>0)
                    p = matrix[i][j] + prev[j-1];
                if(j<n-1)
                    next = matrix[i][j] + prev[j+1];
                
                temp[j]=min(p, min(c, next));
            }
            prev = temp;
        }
        
        return *min_element(prev.begin(), prev.end());
    }
};