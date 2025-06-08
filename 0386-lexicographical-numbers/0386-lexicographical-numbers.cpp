class Solution {
    vector<int> lexicalSorted;
public:
    vector<int> lexicalOrder(int n) {
        for (int i=1; i<=9; i++) {
            dfs(i, n);
        }

        return lexicalSorted;
    }
private:
    void dfs(int cur, int n) {
        if(cur>n)
            return;
        
        lexicalSorted.push_back(cur);
        for(int dig =0; dig<=9; dig++) {
            int next = cur*10+dig;
            if(next>n)
                break; 
            dfs(next, n);
        }
    }
};