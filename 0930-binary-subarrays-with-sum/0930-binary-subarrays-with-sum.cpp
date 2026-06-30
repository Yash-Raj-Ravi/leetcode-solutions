// // 1.Brute
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             int sum=0;
//             for (int j = i; j < n; j++) {
//                 sum+= nums[j];
//                 if (goal == sum ) {
//                     count++;
//                 } 
//                 }
//             }
//         return count;
//     }
// };

// // 2.Better
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         unordered_map<int,int> prefixSum;
//         prefixSum[0]=1;
//         int n = nums.size();
//         int sum=0;
//         int count=0;
//         for(int i=0;i<n;i++)
//         {
//             sum+= nums[i];
//             if(prefixSum.find(sum-goal)!=prefixSum.end())
//             {
//                 count+= prefixSum[sum-goal];
//             }
//             prefixSum[sum]++;
//         }
//         return count;
//     }
// };

// // 3.Optimal
class Solution {
public:

int atmost(int x,vector<int>& nums)
{

     int l=0; int n = nums.size();
     int count=0;int total=0;
     int sum=0;
      for(int r=0;r<n;r++)
        {
           sum+= nums[r];
            while(sum>x)
            {
                sum-= nums[l];
                l++;
            }
            count=r-l+1;
            total+= count;
        }
        return total;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0)
        {
            return atmost(goal,nums);
        }
       return atmost(goal,nums)-atmost(goal-1,nums);
    }
};
