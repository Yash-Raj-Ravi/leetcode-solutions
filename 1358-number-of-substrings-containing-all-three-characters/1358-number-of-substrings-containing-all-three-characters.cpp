// // 1.Brute
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int total=0;
//         for(int i=0;i<n;i++)
//         {
//             int countA=0;
//             int countB=0;
//             int countC=0;
        
//             for(int j=i;j<n;j++){
//             if(s[j]=='a') countA++;
//             if(s[j]=='b') countB++;
//             if(s[j]=='c') countC++;
//             if(countA>=1 && countB>=1 && countC>=1)
//             {
//                 total+=n-j; break;
//             }
//             }
//         }
//         return total;
//     }
// };

// 2.Optimal
class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0; int total=0; int n = s.size();
         int countA=0;
         int countB=0;
         int countC=0;
        for(int r=0;r<n;r++)
        {
            if(s[r]=='a') countA++;
            if(s[r]=='b') countB++;
            if(s[r]=='c') countC++;

            while(countA>=1 && countB>=1 && countC>=1)
            {
                total+= (n-r);
                if(s[l] == 'a') countA--;
                else if(s[l] == 'b') countB--;
                else countC--;
                l++;
            }
            
        }
        return total;
    }
};