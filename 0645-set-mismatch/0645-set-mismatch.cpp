class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n= nums.size();
        int repeated=-1;
        int actual_sum = (n*(n+1))/2;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int sum = accumulate(nums.begin(),nums.end(),0);
        for(auto it:mp)
        {
            if(it.second>1)
            {
                repeated=it.first;
            }
        }
        if(sum < actual_sum)
         return {repeated,repeated + actual_sum - sum};
        return {repeated,repeated- (sum-actual_sum)};

    }
};