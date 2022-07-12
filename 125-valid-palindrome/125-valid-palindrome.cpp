class Solution {
public:
    // bool help(string s, int i, int j){
    //     if(i>=j)
    //         return true;
    //     if(!isalnum(s[i]))
    //         return help(s, i+1, j);
    //     if(!isalnum(s[j]))
    //         return help(s, i, j-1);     
    //     if(toupper(s[i]) != toupper(s[j]))
    //         return false;
    //     return help(s, i+1, j-1);
    // }
    bool isPalindrome(string s) {
        // return help(s, 0, s.length()-1);
        
        int i=0, j=s.length()-1;
        while(i<j){
            while(!isalnum(s[i]) && i<j) i++;
            while(!isalnum(s[j]) && i<j) j--;
            if(tolower(s[i++]) != tolower(s[j--]))
                return false;
        }
        
        return true;
    }
};