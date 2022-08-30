class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        if(s.size() < p.size())
            return res;

        vector<int>freq(26,0), window(26,0);
        int i;
        for(i=0; i<p.length();i++){
            freq[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if(freq == window)
            res.push_back(0);
        for(; i<s.length();i++){
            window[s[i-p.size()]-'a']--;
            window[s[i]-'a']++;
            
            if(window == freq)
                res.push_back(i-p.size()+1);
        }
            
        return res;
    }
};