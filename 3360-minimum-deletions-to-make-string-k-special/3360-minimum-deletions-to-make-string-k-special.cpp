class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>freq(26, 0);
        for(auto w: word) {
            freq[w-'a']++;
        }
        int res = INT_MAX, i=0;

        for(i=0; i<26; i++) {
            int del = 0;
            for(auto f:freq) {
                if(f < freq[i])
                    del += f;
                else if (f - freq[i] > k) 
                    del += f-freq[i]-k;
            }
            res = min(res, del);
        }
    
        return res;
    }
};