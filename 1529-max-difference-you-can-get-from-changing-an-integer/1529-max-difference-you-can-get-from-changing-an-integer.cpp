class Solution {
public:
    int maxDiff(int num) {
        string ogNum = to_string(num);
        bool startsWithOne = ogNum[0] == '1';
        string maxNum, minNum;
        char max, min='a';
        for(auto c: ogNum){
            if(c != '9'){
                max = c;
                break;
            }
        }

        for(auto c: ogNum) {
            if(startsWithOne && c!='0' && c!='1') {
                min = c;
                break;
            }

            else if (!startsWithOne && c!='1') {
                min = c;
                break;
            }
        }

        for(auto c: ogNum) {
            maxNum += c == max ? '9' : c;
            minNum += c == min ? (startsWithOne ? '0' : '1') : c;
        }
        //cout<<stoi(maxNum)<<" "<<stoi(minNum);
        return stoi(maxNum) - stoi(minNum);
    }
};