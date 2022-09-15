class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>res;
        int n = changed.size();
        if(n&1)
            return res;
        unordered_map<int, int>mp;
        for(auto i : changed)
            mp[i]++;
        sort(changed.begin(), changed.end());
        for(auto i:changed){
            if(mp[i]>0){
                if(mp[i*2]>0){
                    mp[i*2]--;
                    mp[i]--;
                    res.push_back(i);
                }
                else return {};
            }
        }
        
        return res;
    }
};