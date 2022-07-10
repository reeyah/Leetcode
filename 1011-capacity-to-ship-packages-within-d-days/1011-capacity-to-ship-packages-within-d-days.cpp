class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min = *max_element(weights.begin(), weights.end());
        int max = accumulate(weights.begin(), weights.end(), 0);
        
        while(min<max){
            int mid = min + (max-min)/2, count = 1, sum = 0;
            for(int i =0; i< weights.size(); i++){
                sum+= weights[i];
                if(sum>mid){
                    count ++;
                    sum = weights[i];
                }
            }
            if(count > days)
                min = mid + 1;
            else if(count <= days)
                max = mid;
        }
        
        return min;
    }
};