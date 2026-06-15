class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       set<vector<int>> powerset;
        int n = nums.size();
        int total = 1 << n;
        for(int mask=0;mask<total;mask++)
        {
            vector<int> ans;
            for(int i=0;i<n;i++)
            {
            if(mask & (1<<i))
                {
                    ans.push_back(nums[i]);
                }
            }
            powerset.insert(ans);
        }
        vector<vector<int>> ans(powerset.begin(), powerset.end());
        return ans;
    }
};
// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        vector<vector<int>>powerset;
//         vector<int> ans;
        

//     }
// };