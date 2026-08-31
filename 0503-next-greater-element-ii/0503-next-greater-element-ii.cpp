// 1.My approach (Need Space optimization by avoiding newNums array)
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> newNums(nums); // Initialize new vector with copy of first then append the first array at back.
//         newNums.insert(newNums.end(),nums.begin(),nums.end()); // "Insert a copy of everything in nums at the end of newNums."
//         stack<int> st;

//         vector<int> ans(2*n);
        
//         for(int i=2*n-1; i>=0; i--)
//         {
//             while(!st.empty() && st.top()<=newNums[i]){
//                 st.pop();
//             }
//             if(st.empty()) ans[i] = -1;
//             else
//              ans[i] = st.top();
//             st.push(newNums[i]);
//         }
//         vector<int> Finalans(ans.begin(),ans.begin() + n);

//         return Finalans;
//     }

// };

// 2.Space Optimization
// Rather than actually taking an array of 2*n size, just think of it virtually by using index % n to access the elements circularly.

// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> ans(n,-1);
        
//         for(int i=0; i<n; i++)
//         {
//             for(int j=i+1;j<i+n; j++)
//             {
//                 int idx = j%n;
//                 if(nums[idx] > nums[i]){
//                     ans[i] = nums[idx]; break;
//                 }
//             }
//         }

//         return ans;
//     }

// };

// It gets space optimized above but now taking time O(n*n) so now lets optimize both.

// 3.Time + Space optimized
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
 
        stack<int> st;

        vector<int> ans(n);
        
        for(int i=2*n-1; i>=0; i--)
        {
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
            if(st.empty()) ans[i] = -1;
            else
             ans[i] = st.top();
            }
            st.push(nums[i%n]);
        }

        return ans;
    }

};