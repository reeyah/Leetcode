class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int win=0;
        vector<int>ch(256, -1);
        for(int i=0, j=-1; i<s.length(); i++){
            if(ch[s[i]] > j)
                j = ch[s[i]];
            //cout<<j<<" ";
            ch[s[i]] = i;
            win=max(win, i-j);
        }
        return win;
    }
};