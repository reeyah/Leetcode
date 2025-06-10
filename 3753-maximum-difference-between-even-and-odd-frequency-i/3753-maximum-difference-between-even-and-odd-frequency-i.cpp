class Solution {
public:
    int maxDifference(string s) {
        int even=INT_MAX, odd=0;
        vector<int>freq(26,0);
        for(auto c:s){
            freq[c-'a']++;
        }
        for(int i=0; i<26; i++) {
            if(freq[i]%2)
                odd = max(odd, freq[i]);
            else if(freq[i] != 0)
                even = min(even, freq[i]);
        }

        return odd-even;
    }
};