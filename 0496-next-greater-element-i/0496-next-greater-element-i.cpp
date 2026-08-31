class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        stack<int> st;
        vector<int> nge2(n);
        vector<int> nge1(m);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>=st.top())
            {
                st.pop();
            }
            if(st.empty()) nge2[i] = -1;
            else
             nge2[i] = st.top();
            st.push(nums2[i]);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    nge1[i] = nge2[j];
                }
            }
        }
        return nge1;
    }
};

