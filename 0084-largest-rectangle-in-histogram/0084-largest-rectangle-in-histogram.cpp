// // 1.Brute
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int largest = -1e9;
//         for(int start=0;start<n;start++){
//             int area = 0;
//             int minHeight = 1e9; 
//             for(int end=start;end<n;end++){
//                 minHeight = min(minHeight,heights[end]);
//                 area = (end-start+1)*minHeight;
//                 largest = max(largest,area);
//             }
//         }
//         return largest;
//     }
// };


class Solution {
private:
 vector<int> getnse(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int j=n-1;j>=0;j--){
            while(!st.empty() && arr[j]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()) nse[j] = n;
            else {
             nse[j] = st.top();
            }
            st.push(j);
         }
        return nse;
    }
   vector<int> getpse(vector<int>& arr) // Previous smaller or equal // equal is taken to handle edge case of overlappping.
    {
        int n = arr.size();
        vector<int> pse(n,-1);
        stack<int> st;
        for(int j=0;j<n;j++){
            while(!st.empty() && arr[j]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()) pse[j] = -1;
            else {
                pse[j] = st.top();
            }
            st.push(j);
         }
        return pse;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse = getpse(heights); 
        vector<int> nse = getnse(heights);
        long long largest = 0;
       
        for(int i=0;i<n;i++){
            long long width = nse[i] - pse[i] - 1;
            largest = max(largest, width*heights[i]);
        }
        return largest;
    }
};


// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
        
//     }
// };