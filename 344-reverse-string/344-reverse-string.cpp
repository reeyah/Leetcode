class Solution {
public:
    void reverseString(vector<char>& s, int i = 0) {
        // int i = 0, j = s.size()-1;
        // while(i<j)
        //     swap(s[i++], s[j--]);
        if(i >= (s.size()/2))
            return ;
        swap(s[i], s[s.size() - 1 - i++]);
        reverseString(s, i);
    }
};