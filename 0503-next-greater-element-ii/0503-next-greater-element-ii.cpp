class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(nums);
        newNums.insert(newNums.end(),nums.begin(),nums.end()); // "Insert a copy of everything in nums at the end of newNums."
        stack<int> st;

        vector<int> ans(2*n);
        
        for(int i=2*n-1; i>=0; i--)
        {
            while(!st.empty() && st.top()<=newNums[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else
             ans[i] = st.top();
            st.push(newNums[i]);
        }
        vector<int> Finalans(ans.begin(),ans.begin() + n);

        return Finalans;
    }

};