// // 1.Brute
// class Solution {
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int maxi=*max_element(nums.begin(),nums.end());
//         for(int i=1;i<=maxi;i++)
//         {
//             int sumofdiv=0;
//             for(auto val:nums)
//             {
//                 sumofdiv+= (val + i -1)/i;
//             }
//             if(sumofdiv<=threshold)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// 2.Optimal
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
      int maxi=*max_element(nums.begin(),nums.end());
      int low=1;
      int high=maxi;
      int ans=maxi;
      while(low<=high)
      {
        int mid = low + (high-low)/2;
        int sum=0;
        for(auto val:nums)
        {
            sum+= (val+mid-1)/mid;
        }
       
        if(sum>threshold)
        {
            low=mid+1; // Sum is greater than required so to decrease the sum we need to increase the divisor value
        }
        else
        {
            ans=mid;
            high=mid-1;
        }
      }
      return ans;
    }
};