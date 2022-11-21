class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(), n=maze[0].size();
        vector<int>dir={0,1,0,-1,0};
        queue<pair<int,int>>q;
        q.push({entrance[0], entrance[1]});
        int steps=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto p = q.front();
                int x = p.first, y = p.second;
                q.pop();
                if((x!=entrance[0] || y!=entrance[1]) && (x==0 || y==0 || x==m-1 || y==n-1))
                    return steps;
                for(int i=0; i<4; i++){
                    int x1=x+dir[i], y1=y+dir[i+1];
                    if(x1>=0 && x1<m && y1>=0 && y1<n && maze[x1][y1]=='.'){
                        q.push({x1,y1});
                        maze[x1][y1]='+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};