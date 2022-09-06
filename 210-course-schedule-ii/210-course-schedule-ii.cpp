class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>graph(numCourses);
        for(auto p: prerequisites){
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int>res;
        while(!q.empty()){
            int c = q.front();
            q.pop();
            res.push_back(c);
            for(auto g:graph[c]){
                indegree[g]--;
                if(indegree[g]==0)
                    q.push(g);
            }
        }
        
        if(res.size()==numCourses)
            return res;
        else return {};
    }
};