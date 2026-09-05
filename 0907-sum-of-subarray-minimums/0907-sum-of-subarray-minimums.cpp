// // 1.Brute
// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         int mod = 1e9 + 7;
//         int sum = 0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 int minVal=1e9; // It needs reset for each subarray.
//                 for(int k=i;k<=j;k++){
//                 if(arr[k] < minVal) minVal = arr[k];
//                 }
//           // Add and immediately apply the modulo to keep 'sum' within range
//             sum = (sum + minVal) % mod;
//             }
          
//         }
//         return sum;
//     }
// };

// // 2.Brute (Using 2 nested loops rather than 3 as above)
// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         int mod = 1e9 + 7;
//         int sum = 0;
//         for(int i=0;i<n;i++){
//             int minVal=1e9; // It needs reset for each subarray.
//             for(int j=i;j<n;j++){
//                minVal = min(minVal,arr[j]);
              
//           // Add and immediately apply the modulo to keep 'sum' within range
//             sum = (sum + minVal) % mod;
//             }
          
//         }
//         return sum;
//     }
// };

// 3.Optimal
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
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = getpse(arr); 
        vector<int> nse = getnse(arr);
        int mod = 1e9 + 7;
        long long ans = 0;
       
        for(int i=0;i<n;i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans = (ans + (1LL * left * right * arr[i]) % mod) % mod;
        }
        return ans;
    }
};