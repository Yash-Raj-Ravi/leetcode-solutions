// // 1.Brute
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         int move = n-k+1;
//         vector<int> ans;
//         for(int i=0;i<move;i++){
//             int maxVal = -1e9;
//             for(int j=i;j<i+k;j++){
//                 if(nums[j]>maxVal) maxVal = nums[j];
//             }
//             ans.push_back(maxVal);
//         }
//         return ans;
//     }
// };

// 2.Optimal
// we need a data structure which allows us to keep track of exact 'k' elements, if it goes k+1 then delete the earliest element from window and add the recent one and continue.
// so we need DS which allows deletion and insertion thus the DS must be open from both ens thus it will be deque.
// The right side of the deque will be used as monotonic stack while the left side will be used for deletions.
// The montonic stack is maintained in decreasing order of values of nums with there indices being pushed in the stack.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for(int i=0;i<n;i++){
            // Remove elements which are out of current window
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            // Remove elements fron deque which are smaller than the newly added element in the same window, since we need max from each window so those elements which are already smaller in the current window and lie at left of larger elements can no way serve any purpose in subsequent windows.
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            // start adding the dq.front() tto ans after 1st window is completed onwards.
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }

        }
        return ans;
    }
};