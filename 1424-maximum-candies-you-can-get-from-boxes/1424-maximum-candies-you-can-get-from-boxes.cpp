class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        /* won't work if one box comes multiple times*/
        deque<int> dq;

        for(auto box: initialBoxes){
            if(status[box])
                dq.push_front(box);
            else
                dq.push_back(box);
        }

        int candy = 0;
        while(!dq.empty()){
            int box = dq.front();
            dq.pop_front();

            if(!status[box])
                break;
            
            candy += candies[box];
            for(auto key:keys[box]){
                status[key] = 1;
            }
            

            for(auto innerBox : containedBoxes[box]){
                if(status[innerBox])
                    dq.push_front(innerBox);
                else
                    dq.push_back(innerBox);
            }
        }

        return candy;
    }
};