class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1,s2;
        int n = s.length(), m = t.length(),i,j;
        for(i=0, j=0; i<n && j<m; i++,j++){
            if(s[i]=='#'){
                if(!s1.empty())
                    s1.pop();
            }
            else s1.push(s[i]);
            if(t[j]=='#'){
                if(!s2.empty())
                    s2.pop();
            }
            else s2.push(t[j]);
        }
        
        while(i<n){
            if(s[i]=='#'){
                if(!s1.empty())
                    s1.pop();
            }
            else s1.push(s[i]);
            i++;
        }
        
        while(j<m){
            if(t[j]=='#'){
                if(!s2.empty())
                    s2.pop();
            }
            else s2.push(t[j]);
            j++;
        }
                
        if(s1.size()!=s2.size())
            return false;
        
        while(!s1.empty()){
            if(s1.top() != s2.top()){
                return false;
            }
            else {
                s1.pop();
                s2.pop();
            }
        }
        return true;
    }
};