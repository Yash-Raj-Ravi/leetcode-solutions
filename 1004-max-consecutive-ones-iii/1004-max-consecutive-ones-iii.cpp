// // 1.Brute
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int maxlen=0;
       
//         for(int i=0;i<n;i++)
//         {
//            int zeroscount=0;
//             for(int j=i;j<n;j++)
//             {
//                 if(nums[j]==0)
//                 {
//                     zeroscount++;
//                 }
//               if(zeroscount>k)
//                 {
//                    break;
//                 }
//                 else
//                 {
//                     int len = j-i+1;
//                     maxlen=max(len,maxlen);
//                 }
//             }
//         }
//         return maxlen;
//     }
// };

// 2.Better
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int n = nums.size();
        int maxlen=0;
        int zeroscount=0;
        for(int r=0;r<n;r++)
        {
            if(nums[r]==0)
                {
                    zeroscount++;
                }
              while (zeroscount>k)
                {
                    if(nums[l]==0)
                    {
                        zeroscount--;
                    }
                     l++;
                }
             int len = r-l+1;
             maxlen=max(len,maxlen);
                
        }
        return maxlen;
    }
};