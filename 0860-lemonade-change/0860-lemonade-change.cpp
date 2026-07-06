// class Solution {
// public:
//     bool lemonadeChange(vector<int>& bills) {
//         int n = bills.size();
//         unordered_map<int,int> changefreq;
//         for(int i=0;i<n;i++)
//         {
//             changefreq[bills[i]]++;
//             if(bills[i]==10)
//             {
//                 if(changefreq[5]==0) return false;
//                 else
//                  changefreq[5]--;
//             }
//             else if(bills[i]==20)
//             {
//               if(changefreq[5]>0 && changefreq[10]>0)
//                 {
//                     changefreq[5]--;changefreq[10]--;
//                 }
//                 else if(changefreq[5]>=3)
//                 {
//                     changefreq[5]-=3;
//                 }
//                 else
//                  return false;
//             }
//         }
//         return true;
//     }
// };

// Using Counter instead of map
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int countfive=0;
        int countten=0;
        for(int i=0;i<n;i++)
        {
            if (bills[i]==5) countfive++;
            if(bills[i]==10)
            {
                if(countfive>0) 
                 {countfive--;
                 countten++;}
                else
                 return false;
            }
            else if(bills[i]==20)
            {
              if(countfive>0 && countten>0)
                {
                    countfive--;countten--;
                }
                else if(countfive>=3)
                {
                    countfive-=3;
                }
                else
                 return false;
            }
        }
        return true;
    }
};