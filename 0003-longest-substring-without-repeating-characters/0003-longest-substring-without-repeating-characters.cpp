// // 1.Brute
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n=s.size();
//         int maxlen=0;
//         for(int i=0;i<n;i++)
//         {
//             vector<int> hash(256,0);
//             for(int j=i;j<n;j++)
//             {
//                 if(hash[s[j]]==1) {
//                     break;// since character already present thus duplicate
//                 }
//                 // else
//                 hash[s[j]]=1;
//                 int len=j-i+1;
//                 maxlen=max(maxlen,len);

//             }
//         }
//         return maxlen;
//     }
// };

// 2.Optimal (Sliding window)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0;
        int maxlen=0;
        int hashlen=256;
        int hash[hashlen];
        // Initialize hashlen to -1 indicating no last occurrences at start.
        for(int i=0;i<hashlen;i++)
        {
            hash[i]=-1;
        }
        while(r<n)
        {
            if(hash[s[r]]!=-1)
            {
                l=max(hash[s[r]]+1,l);
            }
            int len = r-l+1;
            maxlen=max(maxlen,len);

            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};