class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string format;
        int count = 0;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]=='-')
                continue;
            if(s[i]>='a' && s[i]<='z')
                format+= s[i]^32;
            else format+=s[i];
            count++;
            if(count == k){
                format+= '-';
                count = 0;
            }
        }
        if(format.back() == '-')
            format.pop_back();
        reverse(format.begin(), format.end());
        return format;
    }
};