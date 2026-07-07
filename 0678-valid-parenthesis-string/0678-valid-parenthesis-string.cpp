// // 1.Brute
// class Solution {
// public:

// bool helper(int idx,const string &s,int LP)
// {
//     int n = s.size();
//     if(idx == n) return LP==0;

//     if(LP<0) return false;
   

//     if(s[idx]=='(') return helper(idx+1,s,LP+1);
//     else if(s[idx]==')') return helper(idx+1,s,LP-1);
  
//  return 
//     helper(idx+1,s,LP)||
//      helper(idx+1,s,LP-1)||
//       helper(idx+1,s,LP+1);
    
// }
//     bool checkValidString(string s) {
//         int countLP=0;
//         return helper(0,s,0);
//     }
// };

// 2.Optimal (Greedy)
class Solution {
public:
    bool checkValidString(string s) {
        int minOpen=0,maxOpen=0;

        for(char c:s)
        {
            if(c=='('){
                minOpen++;maxOpen++;
            }
           else if(c==')'){
                minOpen--;maxOpen--;
                if(maxOpen<0) return false;
            }
            else // *
            {
                minOpen--;maxOpen++;
            }
            minOpen=max(minOpen,0);
        }
        return minOpen==0;
    }
};