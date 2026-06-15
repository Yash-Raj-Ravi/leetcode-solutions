class Solution {
public:

void helper(int index,string digits,vector<string> &arr,string s,string combos[])
{
    if(index==digits.size())
    {
        arr.push_back(s);return;
    }
    // Generate integer corresponding to character of digits like "2"-> 2
    int digit = digits[index]-'0';
    for(int i=0;i<combos[digit].size();i++)
    {
            // Recursively call function with next index
            // Add current character to the string
        helper(index+1,digits,arr,s+combos[digit][i],combos);
    }
   
}
    vector<string> letterCombinations(string digits) {
        vector<string> arr;
        string s="";
        string combos[] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(0,digits,arr,s,combos);
        return arr;
    }
};