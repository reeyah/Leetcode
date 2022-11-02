class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st{bank.begin(), bank.end()};
        if(st.find(end)==st.end())
            return -1;
        queue<string>q;
        q.push(start);
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr == end)
                    return steps;
                st.erase(curr);
                for(int i=0; i<8; i++){
                    string t = curr;
                    t[i]='A';
                    if(st.count(t))
                        q.push(t);
                    t[i]='C';
                    if(st.count(t))
                        q.push(t);
                    t[i]='G';
                    if(st.count(t))
                        q.push(t);
                    t[i]='T';
                    if(st.count(t))
                        q.push(t);
                }
            }
            steps++;
        }
        return -1;
    }
};