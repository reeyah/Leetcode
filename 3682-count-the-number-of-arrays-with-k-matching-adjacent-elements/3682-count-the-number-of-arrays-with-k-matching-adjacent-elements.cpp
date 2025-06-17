class Solution {
private:
    const int mod = 1e9 + 7;
    
    long long modInverse(long long a, long long m) {
        long long res = 1;
        long long power = m - 2;

        while(power) {
            if(power&1) 
                res = (res * a) % m;
            a = (a * a) % m;
            power >>= 1;
        }

        return res;
    }

    int nCr(int n, int r) {
        if(r > n)
            return 0;
        
        if(r == 0 || r == n)
            return 1;
        
        long long res = 1;

        for(int i = 1; i <= r; i++) {
            res = res * (n - r + i) % mod;
            res = res * modInverse(i, mod) % mod;
        }

        return (int)res;
    }

    long long binExpo(long long a, long long b) {
        long long result = 1;
        while (b) {
            if (b & 1)
                result = (result * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return result;
    }

public:
    int countGoodArrays(int n, int m, int k) {

        int formula = (m * 1LL * binExpo(m-1, n-k-1)) % mod;
        int final = (formula * 1LL * nCr(n-1, k)) % mod;

        return final;
    }
};