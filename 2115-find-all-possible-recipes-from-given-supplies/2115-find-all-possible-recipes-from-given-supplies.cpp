class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string>res;
        int n = recipes.size();
        unordered_set<string>s;
        for(auto st:supplies)
            s.insert(st);
        unordered_map<string, int>indegree;
        for(auto x: recipes)
            indegree[x]=0;
        unordered_map<string,vector<string>> graph;

        for(int i=0; i<n; i++){
            for(int j=0; j<ingredients[i].size(); j++){
                if(s.find(ingredients[i][j]) == s.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        
        queue<string>q;
        for(auto i: indegree){
            if(i.second == 0)
                q.push(i.first);
        }
        
        while(!q.empty()){
            string temp = q.front();
            q.pop();
            res.push_back(temp);
            for(auto j:graph[temp]){
                indegree[j]--;
                if(indegree[j]==0)
                    q.push(j);
            }
        }
        
        return res;
    }
};