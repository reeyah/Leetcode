class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;

        unordered_map<int, int> nge;
        stack<int>st;

        for(auto num: nums2) {
            while(!st.empty() && st.top() < num) {
                nge[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }

        for(auto num: nums1) {
            res.push_back(nge[num]);
        }

        return res;
    }
};