class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicalSorted;
        for (int i=1; i<=9; i++) {
            dfs(i, n, lexicalSorted);
        }
        return lexicalSorted;
    }
private:
    void dfs(int cur, int n, vector<int> &lexicalSorted) {
        if(cur>n)
            return;
        
        lexicalSorted.push_back(cur);
        for(int dig =0; dig<=9; dig++) {
            int next = cur*10+dig;
            if(next>n)
                break; //taken care of by return statement but early exit
            dfs(next, n, lexicalSorted);
        }
    }
};