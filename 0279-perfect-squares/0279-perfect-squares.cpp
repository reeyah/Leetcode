class Solution {
    bool isSquare(int n){
        int sqrtN = (int)sqrt(n);
        return sqrtN*sqrtN==n;
    }
public:
    int numSquares(int n) {
        if(isSquare(n))
            return 1;
        while((n&3)==0)
            n>>=2;
        while((n&7)==7)
            return 4;
        int sqrtN = (int)sqrt(n);
        for(int i = 1; i <= sqrtN; i++)
            if (isSquare(n - i*i)) 
                return 2;
        return 3;
    }
};