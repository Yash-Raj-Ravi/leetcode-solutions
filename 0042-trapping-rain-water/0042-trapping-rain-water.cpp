// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int start = 0; int end = 2;
//         int ans = 0;
//         while(end<n)
//         {
//             if(start>0 && end>0){
//                 while(end < n && height[end] < height[start]){
//                     end++;
//                 }
//                 if(end==n) break;
//                 int gap = end-start-1;
//                 int h = min(height[start],height[end]); // Height of smaller
//                 ans+= h*gap - accumulate(height.begin() + start + 1, height.begin() + end,0); // 2nd iterator is exclusive
//                 start = end+1; end = start+2;

//             }
//             else if(start>0 && end==0){
//                 end++;
//             }
//             else if(start==0){
//                 start++; end++;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n); // Stores max value found till index i in height from left end.
        vector<int> suffixMax(n); // Stores max value found till index i in height from right end.

        prefixMax[0] = height[0];
        for(int i=1;i<n;i++)
        {
            prefixMax[i] = max(height[i],prefixMax[i-1]);
        }

        suffixMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixMax[i] = max(height[i],suffixMax[i+1]);
        }

        int ans = 0;
        for(int i=0;i<n;i++)
        {
           int leftMax = prefixMax[i];
           int rightMax = suffixMax[i];

            if(height[i] < leftMax && height[i] <rightMax){
                ans += min(leftMax,rightMax) - height[i];
            }

        }
        return ans;
    }
};