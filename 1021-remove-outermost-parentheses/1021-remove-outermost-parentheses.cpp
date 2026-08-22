class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance=0;
        string ans="";
        for(auto x:s)
        {
            if(x=='(')
            {
                balance++;
                if(balance>1) ans+= x;
            }
            else
            {
                balance--;
                if(balance>0) ans+= x;
            }
        }
        return ans;
    }
};