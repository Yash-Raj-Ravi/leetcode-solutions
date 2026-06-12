// // 1.Brute + Recursion
// class Solution {
// public:

// bool isvalid(string &s)
// {
//     int balance=0;
//     // At any time opening parenthesis count must be >= closing parenthesis count
//     for(auto c:s)
//     {
//         if(c=='(') balance++;
//         else balance--;
//         if(balance<0)
//          {return false;}
//     }
//     // Number of closing and opening brackets must be same at the end.
//     return balance==0;
// }
// void generateALL(int n,string s,vector<string> &ans)
// {
//     if(s.length()==2*n)
//     {
//         if(isvalid(s))
//         {
//             ans.push_back(s);
//         }
//          return;
//     }
//     generateALL(n,s+'(',ans);
//     generateALL(n,s+')',ans);
// }
//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         string s;
//         generateALL(n,s,ans);
//         return ans;
//     }
// };

// 2.Optimizied Recursion
class Solution {
public:
void generatevalidStrings(int n,string s,int open,int close,vector<string> &ans)
{
//    int open=0;
//    int close=0; // Don't use this rather pass it as parameter otherwise The recursion will have no memory of how many brackets were already used.
 if(s.length()==2*n)
 {
    ans.push_back(s);
    return;
 }
 if(open<n){
   generatevalidStrings(n,s+'(',open+1,close,ans);
  }

 if(open>close)
   {generatevalidStrings(n,s+')',open,close+1,ans);
  }
}

vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ans;
        generatevalidStrings(n,s,0,0,ans);
        return ans;
    }
};