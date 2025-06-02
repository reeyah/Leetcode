class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>candies(n,0);
        candies[0]=1, candies[n-1]=1;
        for(int i=0; i<n-1; i++) {
            if (ratings[i] < ratings[i+1])
                candies[i+1] = candies[i] + 1;
            else candies[i+1] = 1;
        }
        for(int i=n-1; i>0; i--) {
            if ((ratings[i] < ratings[i-1])
                && (candies[i-1] <= candies[i]))
                candies[i-1] = candies[i]+1;
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};