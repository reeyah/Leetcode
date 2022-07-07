class Solution {
public:
    int countDigits(int number){
        int count=0;
        while(number>0){
            number/=10;
            count++;
        }
        //cout<<count;
        return count;
    }
    
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto i: nums){
            //if((i>=10 && i<=99) || (i>=1000 && i<=9999) || i==100000)
            if(!(countDigits(i)&1))
                count++;
        }
        return count;
    }
};