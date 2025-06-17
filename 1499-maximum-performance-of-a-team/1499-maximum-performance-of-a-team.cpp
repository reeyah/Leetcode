class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>>er;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<n; i++)
            er.push_back({efficiency[i],speed[i]});
        sort(er.rbegin(), er.rend());
        long sum=0, res=0;
        for(auto &e:er){
            pq.emplace(e.second);
            sum+= e.second;
            if(pq.size()>k){
                sum-= pq.top();
                pq.pop();
            }
            res = max(res, sum*e.first);
        }
        return res % (int)(1e9+7);
    }
};