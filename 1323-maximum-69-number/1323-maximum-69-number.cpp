class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        for(auto &c:n){
            if(c=='6'){
                c='9';
                break;
            }
        }
        return stoi(n);
    }
};