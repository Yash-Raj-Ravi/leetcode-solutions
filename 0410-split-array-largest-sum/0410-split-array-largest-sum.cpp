// // 1.Brute
// class Solution {
// public:
// int k_value(vector<int> &nums,int sum)
// {
//     int n=nums.size();
//     int k_val=1;
//     long long sum_assigned=0;
//     for(int i=0;i<n;i++){
//     if(nums[i] + sum_assigned <= sum)
//     {
//         sum_assigned+=nums[i];
//     }
//     else
//     {
//         k_val++;
//         sum_assigned=nums[i];
//     }
//     }
//     return k_val;

// }

// int splitArray(vector<int>& nums, int k) {
//     int low=*max_element(nums.begin(),nums.end());
//     int high=accumulate(nums.begin(),nums.end(),0);
//     for(int sum=low;sum<=high;sum++)
//     {
//         if(k_value(nums,sum)<=k)
//         {
//             return sum;
//         }
//     }
//     return -1;
//     }
// };

// 2.Optimal
class Solution {
public:

int k_value(vector<int> &nums,int sum)
{
    int n=nums.size();
    int k_val=1;
    long long sum_assigned=0;
    for(int i=0;i<n;i++){
    if(nums[i] + sum_assigned <= sum)
    {
        sum_assigned+=nums[i];
    }
    else
    {
        k_val++;
        sum_assigned=nums[i];
    }
    }
    return k_val;

}

int splitArray(vector<int>& nums, int k) {
     int low=*max_element(nums.begin(),nums.end());
     int high=accumulate(nums.begin(),nums.end(),0);
     while(low<=high)
     {
        int mid = low + (high-low)/2;
        if(k_value(nums,mid)<=k)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
     }
     return low;
    }
};