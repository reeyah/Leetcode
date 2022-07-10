class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int min = *max_element(nums.begin(), nums.end());
        int max = accumulate(nums.begin(), nums.end(), 0);
        
        while(min<max){
            int mid = min + (max-min)/2, count = 1, sum = 0;
            //cout<<mid<<"\n";
            for(int i =0; i< nums.size(); i++){
                sum+= nums[i];
                //cout<<sum<<" ";
                if(sum>mid){
                    count ++;
                    sum = nums[i];
                }
            }
                
            //cout<<count<<"\n";
            if(count > m)
                min = mid + 1;
            else if(count <= m)
                max = mid;
        }
        
        return min;
    }
};