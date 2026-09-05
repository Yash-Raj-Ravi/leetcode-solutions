// // 1.Brute
// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         int n = nums.size();
//         long long ans = 0;
//         for(int start=0;start<n;start++){
//             int mini = 1e9;
//             int maxi = -1e9;
//             for(int end=start;end<n;end++)
//             {
//                 mini = min(mini,nums[end]);
//                 maxi = max(maxi,nums[end]);
//                 ans+= maxi-mini;
//             }
         
//         }
//         return ans;
//     }
// };

// 2.Optimal
class Solution {
private:
 vector<int> getnse(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int j=n-1;j>=0;j--){
            while(!st.empty() && arr[j]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()) nse[j] = n;
            else {
             nse[j] = st.top();
            }
            st.push(j);
         }
        return nse;
    }
   vector<int> getpse(vector<int>& arr) // Previous smaller or equal // equal is taken to handle edge case of overlappping.
    {
        int n = arr.size();
        vector<int> pse(n,-1);
        stack<int> st;
        for(int j=0;j<n;j++){
            while(!st.empty() && arr[j]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()) pse[j] = -1;
            else {
                pse[j] = st.top();
            }
            st.push(j);
         }
        return pse;
    }

   vector<int> getnge(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;
        for(int j=n-1;j>=0;j--){
            while(!st.empty() && arr[j]>=arr[st.top()]){
                st.pop();
            }
            if(st.empty()) nge[j] = n;
            else {
             nge[j] = st.top();
            }
            st.push(j);
         }
        return nge;
    }
   vector<int> getpge(vector<int>& arr) // Previous smaller or equal // equal is taken to handle edge case of overlappping.
    {
        int n = arr.size();
        vector<int> pge(n,-1);
        stack<int> st;
        for(int j=0;j<n;j++){
            while(!st.empty() && arr[j]>arr[st.top()]){
                st.pop();
            }
            if(st.empty()) pge[j] = -1;
            else {
                pge[j] = st.top();
            }
            st.push(j);
         }
        return pge;
    }
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge = getpge(arr); 
        vector<int> pse = getpse(arr); 
        vector<int> nge = getnge(arr);
        vector<int> nse = getnse(arr);

        long long minSum = 0;
        long long maxSum = 0;
       
        for(int i=0;i<n;i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;
            maxSum = (maxSum + (1LL * left * right * arr[i]));

            long long left2 = i - pse[i];
            long long right2 = nse[i] - i;
            minSum = (minSum + (1LL * left2 * right2 * arr[i]));
        }
        return maxSum - minSum;
    }
};