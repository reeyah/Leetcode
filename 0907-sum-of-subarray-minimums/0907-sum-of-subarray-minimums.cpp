class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int len = arr.size();
        long sum = 0;
        stack<int>st;
        int j, k;

        for (int i = 0; i <= len; i++) {
            while(!st.empty() && arr[st.top()] > (i == len ? INT_MIN : arr[i])){
                j = st.top();
                st.pop();
                k = st.empty() ? -1 : st.top();
                sum += (long)arr[j] * (i - j) * (j - k);
            }
            st.push(i);
        }
        return (int)(sum % (long) (1e9 + 7));
    }
};