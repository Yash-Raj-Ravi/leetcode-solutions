// Uses the idea of largest rectangle in histogram by considering each row as constituent of histogram sequentially.

// 1.Approach-I
// class Solution {
// private:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int largest = 0;
//         stack<int> st;
//         for(int i=0;i<n;i++)
//         {
//             while(!st.empty() && heights[st.top()] > heights[i]){
//                 int element = st.top(); st.pop();
//                 int nse = i; int pse = st.empty()?-1:st.top();
//                 largest = max(largest,(nse-pse-1)*heights[element]);
//             }
//             st.push(i);
//         }
//         while(!st.empty()){
//              int element = st.top(); st.pop();
//              int nse = n; int pse = st.empty()?-1:st.top();
//              largest = max(largest,(nse-pse-1)*heights[element]);
//         }
//         return largest;
//     }
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int largestR= 0;
//         int rows = matrix.size();
//         int cols = matrix[0].size();

//         vector<int> heights(matrix[0].size(), 0);

//         for(int i = 0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(matrix[i][j]=='1') heights[j] += 1;
//                 else heights[j] = 0;
//             }
//             largestR = max(largestR,largestRectangleArea(heights));
//         }

//         return largestR;

//     }
// };

// 2.Optimization (Using prefix sum for histogram bars heights of each row)
class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int largest = 0;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top(); st.pop();
                int nse = i; int pse = st.empty()?-1:st.top();
                largest = max(largest,(nse-pse-1)*heights[element]);
            }
            st.push(i);
        }
        while(!st.empty()){
             int element = st.top(); st.pop();
             int nse = n; int pse = st.empty()?-1:st.top();
             largest = max(largest,(nse-pse-1)*heights[element]);
        }
        return largest;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int largestR= 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> prefixsum(rows,vector<int> (cols,0));

        // column wise traversal to generate the heights properly.
        for(int j=0;j<cols;j++){
            int sum = 0;
            for(int i=0;i<rows;i++){
                if(matrix[i][j]=='1') sum += 1;
                else sum = 0;
                prefixsum[i][j] = sum;
            }
        }

        for(int i=0;i<rows;i++){
            largestR = max(largestR,largestRectangleArea(prefixsum[i]));
        }

        return largestR;

    }
};