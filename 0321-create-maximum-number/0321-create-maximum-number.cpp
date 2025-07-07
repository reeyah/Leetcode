class Solution {
private:
    vector<int> greatSub(vector<int>&nums, int k) {
        vector<int>st;
        int remove = nums.size() - k;
        for(int num: nums) {
            while(!st.empty() && remove && st.back() < num) {
                st.pop_back();
                remove--;
            }
            st.push_back(num);
        }

        st.resize(k);
        return st;
    }

    bool maxSub(vector<int>&a, int i, vector<int>&b, int j) {
        while(i<a.size() && j<b.size()) {
            if(a[i] > b[j])
                return true;
            if(a[i] < b[j])
                return false;
            i++;
            j++;
        }

        return i!=a.size();
    }

    vector<int>merge(vector<int>seq1, vector<int>seq2) {
        vector<int>res;

        int i=0, j=0;

        while(i<seq1.size() || j<seq2.size()) {
            if(maxSub(seq1, i, seq2, j)) {
                res.push_back(seq1[i++]);

            } else {
                res.push_back(seq2[j++]);
            }
        }

        return res;
    }

public:    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;

        int m = nums1.size(), n = nums2.size();
        for(int i = max(0, k-n); i<=min(k,m); i++) { // todo; rethink
            vector<int> seq1 = greatSub(nums1, i);
            vector<int> seq2 = greatSub(nums2, k-i);

            // for(auto s:seq2)
            //     cout<<s;
            // cout<<endl;

            vector<int> temp = merge(seq1, seq2);
            if(maxSub(temp, 0, res, 0))
                res = temp;
        }

        return res;

    }
};