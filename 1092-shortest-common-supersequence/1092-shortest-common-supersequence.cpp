// 1.Tabulation
// LCS followed by forming the answer string based on dp table obtained from lcs.
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int i=m, j=n; // start from last row, last column cell value of dp table
        string ans = "";
        while(i>0 && j>0)
        {
            if(str1[i-1] == str2[j-1]) // Following 1-based indexing shift.
            {
                ans+= str1[i-1]; i--; j--; 
            }
            else if(dp[i-1][j] > dp[i][j-1]) // If characters do not match then move towards max value out of dp[i-1] and dp[j-1]
            {
                ans+= str1[i-1]; i--;
            }
            else // If characters do not match then move towards max value out of dp[i-1] and dp[j-1]
            {
                ans+= str2[j-1]; j--;
            }
        }

        // After taking exit from while loop, Either in str1 or str2 some characters will be there yet, so copy them in the ans.

        while(i>0) {ans += str1[i-1]; i--;}
        while(j>0) {ans += str2[j-1]; j--;}

        reverse(ans.begin(),ans.end());// Reverse is required since we traversed the dp table from back to front.
        return  ans;

    }
};