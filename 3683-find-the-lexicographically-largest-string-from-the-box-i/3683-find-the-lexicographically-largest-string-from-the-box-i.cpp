class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;
        int n = word.size(), length = n-numFriends+1, pos = 0;
        vector<int> startPos;
        for(int i=0; i<n; i++) {
            if(word[pos] < word[i])
                pos = i;
            else if (word[pos] == word[i]) {
                if (startPos.empty())
                    startPos.push_back(i);
                else if(word[startPos[0]] == word[pos])
                    startPos.push_back(i);
                else {
                    startPos.clear();
                    startPos.push_back(i);
                }
            }
        }

        if(word[startPos[0]] != word[pos])
            startPos.clear();
        
        string res = word.substr(pos,length);
        if (startPos.empty())
            return res;

        for(int i = 0; i<startPos.size(); i++) {
            int tempPos = startPos[i];
            string tempRes = word.substr(tempPos,length);
            res = max(res, tempRes);
        }

        return res;
    }
};