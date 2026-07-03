class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_Consecutive=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]==1)
             {
                count++;
                max_Consecutive=max(max_Consecutive,count);
             }
            else
             count=0; // count Resets if streak breaks.
        }
        return max_Consecutive;
    }
};