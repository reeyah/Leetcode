class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res=0, unpaired=0;
        unordered_map<string,int>mp;
        for(auto word:words){
            if(mp.count(word)>0){
                res+=4;
                if(--mp[word] == 0)
                    mp.erase(word);
                if(word[0]==word[1])
                    unpaired--;
            }
            else {       
                if(word[0]==word[1])
                    unpaired++;
                swap(word[0],word[1]);
                mp[word]++;
            }
        }
        if(unpaired>0)
            res+=2;
        return res;
    }
};