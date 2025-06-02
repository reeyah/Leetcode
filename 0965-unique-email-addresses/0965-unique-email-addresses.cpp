class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> uniqueEmails;

        for(auto email:emails) {
            int domainPos = -1, i;
            string trimEmail;
            
            for(i=0; i<email.length(); i++){
                if(email[i] == '.')
                    continue;
                if(email[i] == '+')
                    break;
                if(email[i] == '@') {
                    domainPos = i;
                    break;
                }

                trimEmail+=email[i];
            }

            trimEmail += email.substr(domainPos==-1 ? email.find('@',i) : domainPos);
            uniqueEmails[trimEmail]++;
        }

        return uniqueEmails.size();
    }
};