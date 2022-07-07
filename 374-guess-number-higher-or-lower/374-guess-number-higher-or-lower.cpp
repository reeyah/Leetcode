/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int low = 1, high = n;
        int mid = low + (high-low)/2;
        int g = guess(mid);
        while(g !=0){
            if(g==-1)
                high = mid -1;
            else if(g==1)
                low = mid+1;
            mid = low + (high-low)/2;
            g = guess(mid);
        }
        
        return mid;

    }
};