class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, int>count;
        int i=0;
        for(auto s:strs){
            string str = s;
            sort(str.begin(), str.end());
            if(count.find(str)!=count.end()){
                int j=count[str];
                res[j].push_back(s);
            }
            else {
                count[str]=i;
                i++;
                res.push_back({s});
            }
        }
        return res;
    }
};