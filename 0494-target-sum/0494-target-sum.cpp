// 1.Recursion
class Solution {
private:
    int solve(int idx,int target,vector<int>& nums)
    {
        if(idx==0) 
        {
            if(nums[0]==0 && target==0) return 2;
            if(nums[idx]==abs(target)) return 1;
            else return 0;
        }

        // Take +
        int pos = solve(idx-1,target-nums[idx],nums); // Target can become negative at some point
        // Take -
        int neg = solve(idx-1,target+nums[idx],nums);
    return (pos + neg);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n-1,target,nums);
    }
};


// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
        
//     }
// };