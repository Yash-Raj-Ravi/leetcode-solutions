// // 1.Brute
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//            int len=1;
//            int maxlen=0;
//         for(int i=0;i<s.size()-1;)
//         {
//           for(int j=1;j<s.size();)
//             {
//                 if(s[i]!=s[j] && s.find[j]==string::npos)
//                 {
//                     len++;
//                     j++;
//                     maxlen=max(maxlen,len);
//                 }
//                 else
//                 {
//                     len=1;
//                     i=j;
//                     j++;
//                 }
//             }
//         }
//         return maxlen;
//     }
// };

// 1.Brute
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            vector<int> hash(256,0);
            for(int j=i;j<n;j++)
            {
                if(hash[s[j]]==1) {
                    break;// since character already present thus duplicate
                }
                // else
                hash[s[j]]=1;
                int len=j-i+1;
                maxlen=max(maxlen,len);

            }
        }
        return maxlen;
    }
};

// 2.Optimal
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
        
//     }
// };