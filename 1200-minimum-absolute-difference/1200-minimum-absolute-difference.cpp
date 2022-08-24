class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>res;
        sort(arr.begin(), arr.end());
        for(auto i:arr)
            cout<<i<<" ";
        int diff = arr[1]-arr[0];
        for(int i=1; i<arr.size(); i++){
            int curr_diff = arr[i]-arr[i-1];
            if(curr_diff != diff){
               diff = min(curr_diff, diff);
                if(diff == curr_diff && res.size()!=0){
                    while(res.size()!=0)
                        res.pop_back();
                    res.push_back({arr[i-1], arr[i]});
                }
            }
            else res.push_back({arr[i-1], arr[i]});
        }
        return res;
    }
};