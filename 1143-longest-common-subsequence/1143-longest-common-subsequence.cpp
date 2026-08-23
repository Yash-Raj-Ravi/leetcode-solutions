// 5.Space Optimization
class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);

        //for(int i=0;i<=n;i++) prev[i] = 0;
       

        for(int idx1=1;idx1<=m;idx1++)
        {
            for(int idx2=1;idx2<=n;idx2++)
            {
            // Characters match
            if(text1[idx1-1]==text2[idx2-1]) curr[idx2] = 1 + prev[idx2-1];

            // Characters do not match
            else curr[idx2] =  max(prev[idx2],curr[idx2-1]);
            }
            prev = curr;
        }
        return prev[n];
    }
};