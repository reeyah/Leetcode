class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i=1; i<numRows; i++) {
            vector<int>row;
            for(int j=0; j<=i; j++) {
                int num;
                if(j==0 || j== i)
                    num = 1;
                else {
                    num = res[i-1][j-1] + res[i-1][j];
                }
                row.push_back(num);
            }
            res.push_back(row);
        }

        return res;
    }
};