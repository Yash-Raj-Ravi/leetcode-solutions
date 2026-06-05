// 1.Brute
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(),arr.end());
        int cnt=0;
        int n=arr.size(); 
        for(int i=1;i<=maxi+k;)
        {
        for(int j=0;j<n;)
        {
            if(arr[j]!=i)
            {
                cnt++;
            if(cnt==k)
            {
                return i;
            }
            i++;
            }
            else
            {
                j++;
                i++;
            }
          
        }
     
        }
        return -1;
    }
};

// 2.Optimal
// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
        
//     }
// };