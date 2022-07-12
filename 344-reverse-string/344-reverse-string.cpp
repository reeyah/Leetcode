class Solution {
public:
    void reverse(vector<char>& s, int i, int j){
        if(i>=j)
            return;
        swap(s[i++], s[j--]);
        reverse(s, i, j);
    }
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        // while(i<j)
        //     swap(s[i++], s[j--]);
        reverse(s, i, j);
    }
};