class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int n=arr.size(),i=n-1,curr;
        while(i>=0){
              curr=arr[i];
            while(i>=0 && i!=curr){
                i--;
                curr=min(curr,arr[i]);
            }
            ans++;
            i--;
        }
        return ans;
    }
};