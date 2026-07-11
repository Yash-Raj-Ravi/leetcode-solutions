// // 1.Brute
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> assigned(n,1); // Tracks the number of assigned candies to a child
//         bool changed = true;
//     while(changed){
//         changed = false;
//         for(int i=0;i<n-1;i++)
//         {
//             if(ratings[i]>ratings[i+1] && assigned[i]<=assigned[i+1])
//             {
//                 assigned[i] = assigned[i+1]+1;
//                 changed = true;
//             }
//             if(ratings[i]<ratings[i+1] && assigned[i]>=assigned[i+1])
//             {
//                 assigned[i+1] = assigned[i]+1;
//                 changed = true;
//             }
//         }
//     }
//         return accumulate(assigned.begin(),assigned.end(),0);
//     }
// };

// // 2.Better
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//          int n = ratings.size();
//         vector<int> assigned(n,1); // Tracks the number of assigned candies to a child
 
//         for(int i=0;i<n-1;i++) // left to right pass
//         {
//             if(ratings[i+1]>ratings[i])
//             {
//                 assigned[i+1] = assigned[i]+1;
//             }
//         }

//         for(int i=n-1;i>0;i--) // right to left pass
//         {
//             if(ratings[i-1]>ratings[i])
//             {
//                 assigned[i-1] = max(assigned[i-1],assigned[i]+1);
//             }
//         }
    
//         return accumulate(assigned.begin(),assigned.end(),0);
//     }
// };

// 3.Optimal
class Solution {
public:
    int candy(vector<int>& ratings) {
        int peak=0,valley=0;
        int n = ratings.size();
        int ans=n;

        for(int i=0;i<n-1;)
        {
            peak=0,valley=0;
            if(ratings[i]==ratings[i+1])
            {
                i++; continue;
            }
            while(i<n-1 && ratings[i+1] > ratings[i])
            {
                peak++;
                ans+= peak;
                i++;
            }
            while(i<n-1 && ratings[i+1] < ratings[i])
            {
                valley++;
                ans+= valley;
                i++;
            }
            ans-= min(peak,valley);
        }
        return ans;
    }
};