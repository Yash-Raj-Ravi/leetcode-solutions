// // 1.Brute
// class Solution {
// public:

// bool isvalid(int window[],int need[])
// {
//     for(int c=0;c<128;c++)
//     {
//         if(window[c]<need[c]) return false;
//     }
//     return true;
// }
//     string minWindow(string s, string t) {
//         int m=s.length();
//         int n=t.size();
//         int minLen=INT_MAX;
//         int start=-1;
//         int need[128]={0};
//         for(auto c:t)
//         {
//             need[c]++;
//         }

//         for(int i=0;i<m;i++)
//         {
//             int window[128]={0};
//             for(int j=i;j<m;j++)
//             {
//                 window[s[j]]++;

//                 if(isvalid(window,need))
//                 {
//                     if(j-i+1 < minLen)
//                     {
//                         minLen=j-i+1;
//                         start=i;
//                     }
//                 }
//             }
//         }
//         return start==-1 ? "" : s.substr(start,minLen);
//     }
// };

// // 2.Better
// class Solution {
// public:

// bool isvalid(int window[],int need[])
// {
//     for(int c=0;c<128;c++)
//     {
//         if(window[c]<need[c]) return false;
//     }
//     return true;
// }
//     string minWindow(string s, string t) {
//         int l=0; int m=s.length(); int n=t.size();
//         int minLen=INT_MAX;
//         int start=-1;
//         int need[128]={0};
//         for(auto c:t)
//         {
//             need[c]++;
//         }
//         int window[128]={0};
//         for(int r=0;r<m;r++)
//         {
//             window[s[r]]++;
//               while(isvalid(window,need))
//                 {
//                     if(r-l+1 < minLen)
//                     {
//                         minLen=r-l+1;
//                         start=l;
//                     }
//                     window[s[l]]--; // keep shrinking the window till it remains valid
//                     l++;
//                 }
//         }
//         return start==-1 ? "" : s.substr(start,minLen);
//     }
// };

// 3.Optimal
// Instead of scanning all 128 characters every time,you maintain a variable like 'matched' that tells you immediately whether the window is valid.

class Solution {
public:

    string minWindow(string s, string t) {
        int l=0; int m=s.length(); int n=t.size();
        int minLen=INT_MAX;
        int start=-1;
        int need[128]={0};
        int required=0;
        int matched=0;
        for(auto c:t)
        {
            if(need[c]==0)
            {
                required++;
            }
            need[c]++;
        }

        int window[128]={0};
        for(int r=0;r<m;r++)
        {
            // 1.Expand until window becvomes valid
            window[s[r]]++;
            if(window[s[r]]==need[s[r]]) matched++;

            // Shrink while window is still valid
            while(required==matched)
            {
                if(r-l+1 < minLen)
                {
                    minLen=r-l+1;
                    start=l;
                }
                window[s[l]]--;
                if(window[s[l]] < need[s[l]])
                {
                    matched--;
                }
            l++;
            }
        }
        return start==-1 ? "" : s.substr(start,minLen);
    }
};