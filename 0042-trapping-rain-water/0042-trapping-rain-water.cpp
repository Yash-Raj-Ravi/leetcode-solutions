// 1.Approach-I
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> prefixMax(n); // Stores max value found till index i in height from left end.
//         vector<int> suffixMax(n); // Stores max value found till index i in height from right end.

//         prefixMax[0] = height[0];
//         for(int i=1;i<n;i++)
//         {
//             prefixMax[i] = max(height[i],prefixMax[i-1]);
//         }

//         suffixMax[n-1] = height[n-1];
//         for(int i=n-2;i>=0;i--)
//         {
//             suffixMax[i] = max(height[i],suffixMax[i+1]);
//         }

//         int ans = 0;
//         for(int i=0;i<n;i++)
//         {
//            int leftMax = prefixMax[i];
//            int rightMax = suffixMax[i];

//             if(height[i] < leftMax && height[i] <rightMax){
//                 ans += min(leftMax,rightMax) - height[i];
//             }

//         }
//         return ans;
//     }
// };

// 2.Space Optimization
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        int leftMax=0,rightMax=0;
        int l=0, r=n-1;

        while(l<r)
        {
            if(height[l] <= height[r]){
                if(leftMax > height[l]){
                    ans+= leftMax - height[l];
                }
                else{
                    leftMax = height[l];
                }
                l = l+1;
            }
            else
            {
                if(rightMax > height[r]){
                    ans+= rightMax - height[r];
                }
                else{
                    rightMax = height[r];
                }
                r = r-1;
            }
        }
        
    
        return ans;
    }
};