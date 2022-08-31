class Solution {
public:
    void dfs(vector<vector<int>>&vis, int i, vector<vector<int>>&heights, int j){
        if(vis[i][j] == 1)
            return;
        
        int m = heights.size(), n = heights[0].size();
        vis[i][j]=1;
        
        if (i-1 >= 0 && heights[i-1][j] >= heights[i][j]) 
            dfs(vis, i-1, heights, j);
        if (i+1 < m && heights[i+1][j] >= heights[i][j]) 
            dfs(vis, i+1, heights, j);
        if (j-1 >= 0 && heights[i][j-1] >= heights[i][j]) 
            dfs(vis, i, heights, j-1);
        if (j+1 < n && heights[i][j+1] >= heights[i][j]) 
            dfs(vis, i, heights, j+1);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> P(m, vector<int>(n)), A(m, vector<int>(n)), res;
        for(int i=0; i<m; i++){
            dfs(A, i, heights, 0);
            dfs(P, i, heights, n-1);
        }
        
        for(int i=0; i<n; i++){
            dfs(A, 0, heights, i);
            dfs(P, m-1, heights, i);
        }
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(P[i][j] && A[i][j])
                    res.push_back({i,j});
        return res;
    }
};