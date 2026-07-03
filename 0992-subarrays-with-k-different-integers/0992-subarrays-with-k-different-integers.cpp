// // 1.Brute
// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             unordered_set<int> st;
//             for(int j=i;j<n;j++)
//             {
//                 st.insert(nums[j]);
//                 if(st.size()==k)
//                 {
//                     ans++;
//                 }
//                 else if(st.size()>k) break;
//             }
//         }
//         return ans;
//     }
// };

// 2.Optimal
class Solution {
public:

int atmost(vector<int>& nums, int k)
{
    if(k<0) return 0;
        int n = nums.size();
        int ans=0; int l=0;
        unordered_map<int,int> mp;
        for(int r=0;r<n;r++)
        {
            mp[nums[r]]++;
            while(mp.size()>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
             ans+=r-l+1;
        }
        return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};