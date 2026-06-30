// // 1.Brute
// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         int total = 0;
//         for (int i = 0; i < n; i++) {
//             int countOdds = 0;
//             for (int j = i; j < n; j++) {

//                 if (nums[j] % 2 != 0) {
//                     countOdds++;
//                 }
//                 if (countOdds == k) {
//                     total++;
//                 }
//                 if(countOdds > k) break;
//             }
//         }
//         return total;
//     }
// };

// 2.Better
// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {

//     }
// };

// 3.Optimal
class Solution {
public:
    int countSubarrays(int k, vector<int>& nums) {
        int l = 0;
        int oddCount = 0;
        int total = 0;
        int count = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++) {
        
        if (nums[r] % 2 != 0) {
            oddCount++;
        }
        while (oddCount > k) {
            if (nums[l] % 2 == 1) {
                oddCount--;
            }
            l++;
        }
         count = r - l + 1;
         total+= count;
    
        }
        return total;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // if (k == 0) {
        //     return countSubarrays(k, nums);
        // }  Not required since constraints do not allow k=0.
        return countSubarrays(k, nums) - countSubarrays(k - 1, nums);
    }
};