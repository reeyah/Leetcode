class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1;
        k--;
        while (k > 0) {
            long long count = countSteps(n, current, current + 1);
            //cout<<count<<" "<<current<<"\n";
            if (count <= k) {
                current++;
                k -= count;
            } else {
                current *= 10;
                k--;
            }
        }
        return current;
    }

    int countSteps(int n, long long curr, long long next) {
        long long steps = 0;
        while (curr <= n) {
            steps += min((long long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};