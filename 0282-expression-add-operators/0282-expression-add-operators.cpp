class Solution {
public:

void check(int start,long long curr_val,long long last_operand,string num, int target,vector<string> &ans,string candidate) // DFS
{
    if(start==num.size())
    {
        if(curr_val==target)
        { ans.push_back(candidate);}
        return;
    }

    for(int i=start;i<num.size();i++)
    {
        if(i>start && num[start]=='0') return;
        string current_num=num.substr(start,i-start+1);
        long long current_val= stoll(current_num);
        if(start==0)
        {
            check(i+1,current_val,current_val,num,target,ans,current_num);
        }
        else
        {
            // Addition operator +
            check(i+1,curr_val + current_val,current_val,num,target,ans,candidate + '+' + current_num);
            // Subtraction operator -
            check(i+1,curr_val - current_val,-current_val,num,target,ans,candidate + '-' + current_num);
            // Multiplication operator * (Need to track last operand due to operator * precedence over + & -)
            check(i+1,curr_val - last_operand + last_operand*current_val,last_operand*current_val,num,target,ans,candidate + '*' + current_num);
        }
    }

}
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string candidate="";
        check(0,0,0,num,target,ans,candidate);
        return ans;
    }
};