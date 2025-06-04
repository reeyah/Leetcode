class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;
        int n = word.size(), length = n-numFriends+1;
        char ch = *max_element(word.begin(), word.end());
        vector<int> startPos;
        for(int i=0; i<n; i++) {
            if (word[i]==ch)
                startPos.push_back(i);
        }
        
        string res = length + startPos[0] > n ? word.substr(startPos[0]) : word.substr(startPos[0],length);
        if (startPos.size()==1)
            return res;

        for(int i = 0; i<startPos.size(); i++) {
            int tempPos = startPos[i];
            string tempRes = length + tempPos > n ? word.substr(tempPos) : word.substr(tempPos,length);
            res = max(res, tempRes);
        }

        return res;
    }
};