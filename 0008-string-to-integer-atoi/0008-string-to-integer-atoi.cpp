class Solution {

private:
int helper(string &s,int i,long long num,int sign)
{
    // return if reaches string end or non-digit character encountered
    {
        if(i>=s.size() || !isdigit(s[i]))
        {
            return (int)(sign*num);
        }
        num = num*10 + (s[i]-'0');
    // clamp
     if(sign*num >=INT_MAX) return INT_MAX;
     if(sign*num <=INT_MIN) return INT_MIN;

    return helper(s,i+1,num,sign);
    }
}
public:
    int myAtoi(string s) {
        int i=0;
        // Skip all whitespaces(so use while loop)
        while(i<s.size() && s[i]==' ')
        {
            i++;
        }
        // handle sign
        int sign=1;
        if(i<s.size() && (s[i]=='+' || s[i]=='-'))
        {
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        return helper(s,i,0,sign);
    }
};