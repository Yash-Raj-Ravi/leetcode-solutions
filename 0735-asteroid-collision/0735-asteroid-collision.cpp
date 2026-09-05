class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
       
        for(int i=0;i<n;i++)
        {
            bool destroyed = false;
            while(!st.empty() && asteroids[i] < 0 && st.top() > 0){
            if (abs(asteroids[i]) < st.top()) {
                destroyed = true;
                break;
            }
            else if (abs(asteroids[i]) == st.top()) {
                destroyed = true;
                st.pop();
                break;
                // current asteroid also destroyed
            }
            else {
                st.pop();
                // current asteroid survives, so check next stack asteroid
            }
            }
            if(!destroyed)
             st.push(asteroids[i]);

        }
        int m = st.size();
        vector<int> ans(m);
        for(int j=0;j<m;j++)
        {
            ans[m-j-1] = st.top();
            st.pop();
        }
        return ans;
    }
};