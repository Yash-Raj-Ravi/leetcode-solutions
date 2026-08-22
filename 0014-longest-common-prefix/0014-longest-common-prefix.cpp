// Why does this work? Because after lexicographical sorting, the strings that differ earliest are effectively represented by the extremes. Therefore, the common prefix of all strings is the common prefix of the first and last strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n = strs.size();
        sort(strs.begin(),strs.end());

        int minLen = min(strs[0].size(),strs[n-1].size());

        for(int i=0;i<minLen;i++)
        {
            if(strs[0][i] != strs[n-1][i]) break;

            ans+= strs[0][i];
        }
       
        return ans;
    }
};