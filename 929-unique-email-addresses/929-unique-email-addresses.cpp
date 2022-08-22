class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int>count;
        for(auto s: emails){
            string email;
            for(auto ch: s){
                if(ch =='.')
                    continue;
                if(ch == '+' || ch =='@')
                    break;
                email+=ch;
            }
            email+= s.substr(s.find('@'));
            count[email]++;
        }
        
        return count.size();
    }
};