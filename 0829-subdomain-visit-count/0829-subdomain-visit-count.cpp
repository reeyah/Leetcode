class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> domainCounts;
        unordered_map<string, int>count;
        for(auto cd: cpdomains){
            int pos = cd.find(" ");
            int hits = stoi(cd.substr(0,pos));
            count[cd.substr(pos+1)] += hits;
            for(int i=pos+1; i<cd.size(); i++){
                if(cd[i]=='.')
                    count[cd.substr(i+1)]+=hits;
            }
        }
        for(auto i:count)
            domainCounts.push_back(to_string(i.second)+" "+i.first);
            
        return domainCounts;
    }
};