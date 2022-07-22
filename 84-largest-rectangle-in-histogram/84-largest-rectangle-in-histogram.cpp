class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        // 2 - Pass 
//         int size = heights.size();
//         int left[size], right[size];
//         stack<int> st;
        
//         for(int i = 0; i<size; i++){
//             while(!st.empty() && heights[st.top()]>= heights[i])
//                 st.pop();
//             if(st.empty()) 
//                 left[i] = 0;
//             else left[i]=st.top()+1;
//             st.push(i);
//         }
        
//         while(!st.empty())
//             st.pop();
        
//         for(int i = size-1; i>=0; i--){
//             while(!st.empty() && heights[st.top()]>= heights[i])
//                 st.pop();
//             if(st.empty()) 
//                 right[i] = size-1;
//             else right[i]=st.top()-1;
//             st.push(i);
//         }
        
//         int maxArea = 0;
//         for(int i = 0; i<size; i++){
//             int m = (right[i] - left[i] + 1)*heights[i];
//             maxArea = max(maxArea, m);
//         }
        
//         return maxArea;
        
        //Single Pass
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for(int i =0 ; i<n; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){ // >= will correct for the last duplicagte
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i /*RSE -(-1) - 1*/ : (i - st.top()) -1 ;
                maxArea = max(maxArea, width*height);
            }
            
            st.push(i);
        }
        return maxArea;
    }
};