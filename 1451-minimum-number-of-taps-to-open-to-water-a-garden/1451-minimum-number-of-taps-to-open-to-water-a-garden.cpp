class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> end(n+1, 0);
        for (int i=0; i<=n; i++) {
            int left = max(0, i-ranges[i]);
            int right = min(n, i+ranges[i]);
            end[left] = max(end[left], right);
        }

        int taps = 0, maxFar = 0, currEnd = 0;
        for(int i=0; i<=n; i++) {
            //cout<<end[i]<<" ";
            if(i>currEnd)
                return -1;

            maxFar = max(maxFar, end[i]);

            if (i==currEnd) {
                currEnd = maxFar;
                taps++;
            }

            if (currEnd == n)
                return taps;
        }

        return taps;
    }
};