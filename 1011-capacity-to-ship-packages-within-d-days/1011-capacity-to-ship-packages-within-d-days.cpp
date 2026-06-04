// // 1.Brute
// class Solution {
// public:
//     int shipWithinDays(vector<int>& weights, int days) {
//         int capacity=0;
//         int n=weights.size();
//         int sum=0;
//         int maxi= *max_element(weights.begin(),weights.end());
       
//         for(auto x:weights)
//         {
//             sum+=x;
//         }
//         for(int i=maxi;i<=sum;i++)
//         {
//             capacity=i;
//             int daysrequired=1;
//             int perdaycapacity=0;
//             for(int j=0;j<n;j++)
//             {
//                 perdaycapacity+=weights[j];
//                 if(perdaycapacity>capacity)
//                 {
//                     daysrequired++;
//                     perdaycapacity=weights[j];
//                 }
//             }
//             if(daysrequired<=days)
//             {
//                 return capacity;
//             }

//         }
//         return -1;
//     }
// };

// 2.Optimal
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int maxi= *max_element(weights.begin(),weights.end());
       for(auto x:weights)
        {
            sum+=x;
        }
        int low=maxi;
        int high=sum;
        while(low<high)
        {
            int mid = low + (high-low)/2;
            int capacity=mid;
            int daysrequired=1;
            int perdaycapacity=0;
            for(int i=0;i<weights.size();i++)
            {
                perdaycapacity+=weights[i];
                if(perdaycapacity>capacity)
                {
                    daysrequired++;
                    perdaycapacity=weights[i];
                }
            }
             if(daysrequired<=days)
                {
                    high=mid;
                }
                else
                {
                    low=mid+1;
                }
        }
        return low;
    }
};