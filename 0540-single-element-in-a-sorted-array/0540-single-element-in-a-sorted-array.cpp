// // 1.Brute-I
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int single=-1;
//         if(n==1)
//         {
//             single= nums[0];
//         }
//         else if(nums[0]!=nums[1])
//         {
//             single= nums[0];
//         }
//         else if(nums[n-1]!=nums[n-2])
//         {
//             single= nums[n-1];
//         }
//         else{
//         for(int i=2;i<n-2;i++)
//         {
//             if(nums[i-1]!=nums[i] && nums[i]!=nums[i+1])
//             {
//                 single = nums[i];
//             }
//          }
//         }
//         return single;
//     }
// };

// 2.Brute-II (XOR)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int n = nums.size();
       int single=0;
       for(int i=0;i<n;i++)
       {
        single^=nums[i];
       }
       return single;
    }
};

// 3.Optimal
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int low=0;
//         int high=n-1;
        
//     }
// };