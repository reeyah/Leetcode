class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int, greater<char>> countCh;
        for(auto ch:s)
            countCh[ch]++;
        string ans = "";
        while(!countCh.empty()){
            int freq = countCh.begin()->second, count=0;
            char ch = countCh.begin()->first;
            countCh.erase(countCh.begin());
            while(freq){
                if(count>=repeatLimit){
                    if(countCh.empty()) 
                        return ans;
                    ans+= countCh.begin()->first;
                    countCh.begin()->second--;
                    if (countCh.begin()->second == 0)
                        countCh.erase(countCh.begin());
                    count=0;
                }
                ans+=ch;
                freq--;
                count++;
            }
        }
        return ans;
    }
};