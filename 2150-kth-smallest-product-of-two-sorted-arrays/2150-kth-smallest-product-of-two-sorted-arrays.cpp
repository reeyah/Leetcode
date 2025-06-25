class Solution {
private:
    void posneg(vector<int>& nums, vector<int>& pos, vector<int>&neg) {
        for(auto n:nums) {
            if(n<0)
                neg.push_back(-n);
            else pos.push_back(n);
        }
        reverse(neg.begin(), neg.end());

    }

    long numProductNoGreaterThan(const vector<int>& A, const vector<int>& B,
                               long m) {
        long count = 0;
        int j = B.size() - 1;
        for (const long a : A) {
        while (j >= 0 && a * B[j] > m)
            --j;
        count += j + 1;
        }
        return count;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int> pos1, neg1, pos2, neg2;
        posneg(nums1, pos1, neg1);
        posneg(nums2, pos2, neg2);

        long negCount = 1L * pos1.size() * neg2.size() + 1L * pos2.size() * neg1.size();
        int sign = 1;

        if (k > negCount) {
            k -= negCount;
        } else {
            k = negCount - k + 1;
            sign = -1;
            swap(pos2, neg2);
        }

        long l = 0, r = 1e10;

        while (l < r) {
        const long m = (l + r) / 2;
        if (numProductNoGreaterThan(neg1, neg2, m) +
                numProductNoGreaterThan(pos1, pos2, m) >=k
            )
            r = m;
        else
            l = m + 1;
        }

        return sign * l;
    }
};