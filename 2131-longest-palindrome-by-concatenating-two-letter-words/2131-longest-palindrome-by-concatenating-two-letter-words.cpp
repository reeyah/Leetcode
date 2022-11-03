class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res=0;
        unordered_map<string,int>mp;
        for(auto word:words){
            if(mp.count(word)>0){
                res+=4;
                if(--mp[word] == 0)
                    mp.erase(word);
            }
            else {       
                swap(word[0],word[1]);
                mp[word]++;
            }
        }
        
        for(auto [w,i]:mp){
            if(w[0]==w[1]){
                res+=2;
                break;
            }
            
        }
        return res;
    }
};