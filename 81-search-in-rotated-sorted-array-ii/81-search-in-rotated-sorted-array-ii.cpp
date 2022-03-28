class Solution {
public:
    bool search(vector<int>& A, int t) {
        if (A.empty()) 
            return false;
        
        int l = 0, r = A.size() - 1;
        
        while (l < r) {
            int m = l + (r - l) / 2;    
            if (A[m] == t) return true;
            if (A[l] < A[m]) {
                if (A[l] <= t && t < A[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else if (A[m] < A[r]) {
                if (A[m] < t && t <= A[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if (A[l] == A[m]) l++;
                if (A[m] == A[r]) r--;
            }
        }
        
        return A[l] == t? true : false;
    }
};