class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.length();

        int ans = INT_MIN;

        for(char a = '0'; a <= '4'; a++) {
            for(char b = '0'; b <= '4'; b++) {
                if (a==b)
                    continue;
                
                vector<int>best(4, INT_MAX);

                int cntA = 0, cntB = 0, prevA = 0, prevB = 0, left = -1;

                for(int right = 0; right<n; right++) {
                    cntA += (s[right] == a) ? 1 : 0;
                    cntB += (s[right] == b) ? 1 : 0;

                    while (right-left >= k && cntB - prevB >=2) {
                        int leftStatus = getStatus(prevA, prevB);

                        best[leftStatus] = min(best[leftStatus], prevA-prevB);

                        left++;

                        prevA += s[left] == a ? 1 : 0;
                        prevB += s[left] == b ? 1 : 0;
                    }

                    int rightStatus = getStatus(cntA, cntB);

                    int reqdStatus = rightStatus ^ 0b10;

                    if(best[reqdStatus] != INT_MAX) {
                        ans = max (ans, cntA-cntB-best[reqdStatus]);
                    }
                }
            }
        }
        
        return ans;

    }

private: 
    int getStatus (int a, int b) {
        return ((a&1) << 1) | (b&1);
    }
};