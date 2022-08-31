class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>&visited, int i){
        visited[i] = true;
        for(int j=0; j<visited.size(); j++){
            if(i!=j && isConnected[i][j]==1 && !visited[j])
                dfs(isConnected, visited, j);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty())
            return 0;
        int n = isConnected.size();
        int groups = 0;
        vector<bool>visited(n,false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                groups++;
                dfs(isConnected, visited, i);
            }
        }
        return groups;
    }
};