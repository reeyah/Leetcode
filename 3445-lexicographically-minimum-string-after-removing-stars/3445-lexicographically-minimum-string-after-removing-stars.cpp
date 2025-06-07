class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<bool>v(n, true);
        priority_queue<char, vector<char>, greater<char>> pq; //Min-heap
        unordered_map<char, vector<int>>m;

        for(int i=0; i<n; i++) {
            if(s[i]=='*') {
                char smallest = pq.top();
                int index = m[smallest].back();
                m[smallest].pop_back(); //removing last index
                v[i]=false;
                v[index]=false;
            } else {
                pq.push(s[i]);
                m[s[i]].push_back(i);
            }
        }

        string res = "";
        for(int i=0; i<n; i++){
            if(v[i])
                res+=s[i];
        }

        return res;
    }
};