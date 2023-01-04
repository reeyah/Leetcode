class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int count=0;
        unordered_map<int,int>mp;
        for(auto t:tasks)
            mp[t]++;
        for(auto &i:mp){
            if(i.second==1)
                return -1;
            count+= (i.second+2)/3;
        }
        return count;
    }
};