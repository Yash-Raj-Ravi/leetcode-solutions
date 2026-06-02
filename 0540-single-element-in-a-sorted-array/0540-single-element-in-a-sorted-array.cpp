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
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//        int n = nums.size();
//        int single=0;
//        for(int i=0;i<n;i++)
//        {
//         single^=nums[i];
//        }
//        return single;
//     }
// };

// 3.Optimal
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low=1;
        int high=n-2;

        if(n==1)
        {
            return nums[0]; 
        }
        if(nums[low]!=nums[low-1])
        {
            return nums[low-1]; 
        }
        else if(nums[high]!=nums[high+1])
        {
            return nums[high+1]; 
        }
        else{
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])
            {
              return nums[mid]; 
            }
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2!=0 && nums[mid-1]==nums[mid]))
            // If mid is part of correct pair then it means it is not yet distorted by the single element that means single element is yet to come so it lies to the right part thus shift low to mid+1
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        }
        
        return -1;
    }
};