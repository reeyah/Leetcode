class Solution {
public:
    int minMaxDifference(int num) {
        string ogNum = to_string(num);
        string maxNum, minNum;
        char max, min;
        for(auto c: ogNum) 
            if(c !='9') {
                max = c;
                break;
            }
        for(auto c: ogNum)
            if(c != '0') {
                min = c;
                break;
            }
        
        for(auto c:ogNum) {
            maxNum += c == max ? '9' : c;
            minNum += c == min ? '0' : c;
        }

        return stoi(maxNum) - stoi(minNum);
    }
};