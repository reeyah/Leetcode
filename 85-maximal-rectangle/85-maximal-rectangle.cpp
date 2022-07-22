class Solution {
public:
    int maxHistogram(vector<int>heights){
       heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for(int i =0 ; i<n; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){ 
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i /*RSE -(-1) - 1*/ : (i - st.top()) -1 ;
                maxArea = max(maxArea, width*height);
            }
            
            st.push(i);
        }
        return maxArea; 
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>heights(matrix[0].size(), 0);
        int maxArea=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]=='1')
                    heights[j]++;
                else heights[j]=0;
            }
            maxArea = max(maxArea, maxHistogram(heights));
        }
        
        return maxArea;
    }
};