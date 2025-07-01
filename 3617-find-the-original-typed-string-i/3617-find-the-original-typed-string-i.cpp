class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        for (int i = 0, j = i; i < word.size(); ) {
            while (j < word.size() && word[j] == word[i]) 
                j++;
            ans += (j - i - 1);                     
            i = j;
        }

        return ans;
    }
};