// 1.Brute
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> freq;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(freq[i+1]==0)
            {
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};

// 2.Optimal