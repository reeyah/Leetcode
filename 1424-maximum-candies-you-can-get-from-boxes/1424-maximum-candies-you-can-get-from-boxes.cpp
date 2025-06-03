class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candy = 0, n = candies.size();
        vector<int>visitedBox(n,0), keyFound(n,0), boxInQueue(n,0);
        queue<int>q;
        for(auto box: initialBoxes) {
            q.push(box);
            visitedBox[box]=1;
            boxInQueue[box]=1;
        }

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            boxInQueue[cur] = 0;
            if(status[cur]) {
                visitedBox[cur] = 0;
                candy += candies[cur];
                for(auto key: keys[cur]) {
                    status[key] = 1;
                    if(visitedBox[key] && !keyFound[key] && !boxInQueue[key]){
                        q.push(key);
                        boxInQueue[key]=1;
                    }
                    keyFound[key] = 1;

                }
                for(auto containedBox: containedBoxes[cur]) {
                    if (!boxInQueue[containedBox])
                        q.push(containedBox);
                    visitedBox[containedBox] = 1;
                    boxInQueue[containedBox] = 1;
                }
            }
        }

        return candy;
    }
};