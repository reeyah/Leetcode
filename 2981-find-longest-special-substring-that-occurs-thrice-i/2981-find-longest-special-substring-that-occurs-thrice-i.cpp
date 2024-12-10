class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int left = 1, right = n;

        if (!helper(s, n, left)) 
            return -1;

        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (helper(s, n, mid)) 
                left = mid;
            else right = mid;
        }

        return left;
    }
    
    bool helper(const string& s, int n, int x) {
        vector<int> cnt(26, 0);

        for (int i=0, p=0; i<n; i++) {
            while (s[p] != s[i]) 
                p++;
            if (i - p + 1 >= x) 
                cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] > 2) 
                return true;
        }

        return false;
    }
};