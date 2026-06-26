// // 1.Brute
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.size();
//         int maxlen=0;
//         for(int i=0;i<n;i++)
//         {
//             // Frequecny array taken inside one for loop to keep fresh count of each character in the current substring window.
//             vector<int> freq(26,0);
//             int mostfreq = 0;
//             for(int j=i;j<n;j++)
//             {
//                 freq[s[j]-'A']++;
//             // Number of replacements needed = Window size - Frequency of most common character
//             // We keep the most frequent character and replace the rest.
//             mostfreq = max(mostfreq,freq[s[j]-'A']);
//             int window_Length = j-i+1; // current window length
//             int replace = window_Length - mostfreq;
//                 if(replace <= k)
//                 {
//                     maxlen = max(maxlen,window_Length);
//                 }
//             }
//         }
//         return maxlen;
//     }
// };

// 2.Better
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0;
        int mostfreq = 0;
        int maxlen = 0;
        vector<int> freq(26,0);
      for(int r=0;r<n;r++)
        {
           
            freq[s[r]-'A']++;
            mostfreq = max (mostfreq,freq[s[r]-'A']);
           

              while ( r-l+1  - mostfreq> k)
            { 
                freq[s[l]-'A']--;
                l++;
            }
            
         maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};


// class Solution {
// public:
//     int characterReplacement(string s, int k) {
        
//     }
// };