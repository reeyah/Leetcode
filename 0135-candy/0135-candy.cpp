class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans=0;
        vector<int>candies(n,1);
        for(int i=0; i<n-1; i++) {
            if (ratings[i] < ratings[i+1])
                candies[i+1] = candies[i] + 1;
        }
        for(int i=n-1; i>0; i--) {
            if (ratings[i] < ratings[i-1])
                candies[i-1] = max(candies[i]+1, candies[i-1]);
            ans+=candies[i];
        }
        return ans + candies[0];
    }
};