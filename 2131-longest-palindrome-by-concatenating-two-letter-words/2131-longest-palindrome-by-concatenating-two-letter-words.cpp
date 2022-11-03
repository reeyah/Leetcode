class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res=0;
        unordered_map<string,int>mp;
        for(auto word:words){
            if(mp[word]>0){
                res+=4;
                mp[word]--;
            }
            else {       
                swap(word[0],word[1]);
                mp[word]++;
            }
        }
        
        for(auto [w,i]:mp){
            if(w[0]==w[1] && mp[w]>0){
                res+=2;
                break;
            }
            
        }
        return res;
    }
};