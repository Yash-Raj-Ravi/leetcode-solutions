// 1.Brute
// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int maxi = *max_element(piles.begin(), piles.end());
        
//         for(int k=1;k<=maxi;k++)
//         {
//             long long hours=0;
//             for(auto x:piles)
//             {
//             hours+=(x+k-1)/k;
//             }
//               if(hours<=h)
//             {
//                 return k;
//             }
//         }
//         return -1;
//     }
// };

// 2.Optimal
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi = *max_element(piles.begin(), piles.end());
        int low=1;
        int high=maxi;
        int ans=-1;
       
            while(low<=high)
            {
                long long hours=0;
                int mid = low + (high-low)/2;
                for(auto bananas:piles)
                {
                hours+= (bananas + mid-1)/mid;
                }
                if(hours<=h)
                {
                    ans=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
    return ans;
    }
};