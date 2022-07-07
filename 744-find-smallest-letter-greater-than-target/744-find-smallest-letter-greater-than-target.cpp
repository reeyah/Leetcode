class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0, end = letters.size()-1;
        if(target >= letters[end]) return letters[start];
        while(start<=end){
            int middle = start + (end -start)/2;
            if(letters[middle]<=target)
                start = (middle + 1);
            else end = (middle - 1);
        }
        
        return letters[start];
    }
};