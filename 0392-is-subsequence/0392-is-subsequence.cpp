// 1.Recursion
class Solution {
private:
    bool solve(int i,int j,string &s, string &t)
    {
        if(i<0) return true;
        if(j<0) return false;

        if(s[i]==t[j]) return solve(i-1,j-1,s,t);
        return solve(i,j-1,s,t);
    }
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        return solve(m-1,n-1,s,t);
    }
};