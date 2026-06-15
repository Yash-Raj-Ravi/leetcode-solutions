// // 1.Brute(Bit-masking)
// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        set<vector<int>> powerset;
//         int n = nums.size();
//         int total = 1 << n;
//         for(int mask=0;mask<total;mask++)
//         {
//             vector<int> ans;
//             for(int i=0;i<n;i++)
//             {
//             if(mask & (1<<i))
//                 {
//                     ans.push_back(nums[i]);
//                 }
//             }
//             powerset.insert(ans);
//         }
//         vector<vector<int>> ans(powerset.begin(), powerset.end());
//         return ans;
//     }
// };

// 2.Recursive
class Solution {
public:
void helper(int index,vector<int>& nums,vector<int>& ans,vector<vector<int>> &powerset)
{
    int n= nums.size();
    powerset.push_back(ans);
    for(int i=index;i<n;i++)
    {
        if(i>index && nums[i-1]==nums[i]) continue;

        ans.push_back(nums[i]);
        helper(i+1,nums,ans,powerset);
        ans.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>>powerset;
       vector<int> ans;
       sort(nums.begin(),nums.end());
       helper(0,nums,ans,powerset);
       return powerset;

    }
};