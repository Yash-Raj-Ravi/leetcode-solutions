// // 1.Brute
// class Solution {
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         int maxi = *max_element(bloomDay.begin(),bloomDay.end());
//         int mini = *min_element(bloomDay.begin(),bloomDay.end());
//         if(bloomDay.size()< 1LL*m*k){return -1;}
//         else
//         {
//             for(int day=mini;day<=maxi;day++)
//             {
//               int count=0;
//               int bouquets=0;
//                 for(auto bloom:bloomDay)
//                 {
//                     if(bloom<=day)
//                     {
//                         count++;
//                         if(count==k)
//                         {
//                             bouquets++;
//                             count=0;
//                         }
                      
//                     }
//                     else
//                     {
//                         count=0;
//                     }
//                 }
//                 if(bouquets>=m)
//                 {
//                     return day;
//                 }
//             }
//         }

//         return -1;;
//     }
// };

// 2.Optimal
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi = *max_element(bloomDay.begin(),bloomDay.end());
        int mini = *min_element(bloomDay.begin(),bloomDay.end());
        int low=mini; int high=maxi;
        if(bloomDay.size()< 1LL*m*k){return -1;}
        else
        {
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                int count=0;
                int bouquet=0;
                for(auto bloom:bloomDay)
                {
                    if(bloom<=mid)
                    {
                        count++;
                        if(count==k)
                        {
                            bouquet++;
                            count=0;
                        }
                    }
                    else
                    {
                        count=0;
                    }
                }
                if(bouquet>=m)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
        }
        return low;
    }
};