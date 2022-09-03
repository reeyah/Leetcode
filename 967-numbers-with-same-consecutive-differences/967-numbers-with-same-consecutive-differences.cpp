class Solution {
public:
    void rec(int i, int n, int k, vector<int>&res){
        if(n==1){
            res.push_back(i);
            return;
        }
        if(i%10 -k>=0)
            rec(i*10 + i%10-k, n-1, k, res);
        if(k){
           if(i%10+k<10)
            rec(i*10 + i%10+k, n-1, k, res); 
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        for(int i=1; i<=9; i++)
            rec(i, n, k, res);
        return res;
    }
};