// 1.Brute
class Solution {
public:

bool isvalid(string &s)
{
    int balance=0;
    // At any time opening parenthesis count must be >= closing parenthesis count
    for(auto c:s)
    {
        if(c=='(') balance++;
        else balance--;
        if(balance<0)
         {return false;}
    }
    // Number of closing and opening brackets must be same at the end.
    return balance==0;
}
void generateALL(int n,string s,vector<string> &ans)
{
    if(s.length()==2*n)
    {
        if(isvalid(s))
        {
            ans.push_back(s);
        }
         return;
    }
    generateALL(n,s+'(',ans);
    generateALL(n,s+')',ans);
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        generateALL(n,s,ans);
        return ans;
    }
};

// 2.Optimal
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
        
//     }
// };