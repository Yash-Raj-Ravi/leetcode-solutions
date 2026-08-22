// // 1.Brute
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int n = s.size();

//         if(n!=t.size()) return false;

//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());

//         for(int i=0;i<n;i++)
//         {
//             if(s[i]!=t[i]) return false;
//         }
//         return true;
//     }
// };

// // 2.Brute (Direct)
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int n = s.size();

//         if(n!=t.size()) return false;

//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());

//         return s==t; 
//     }
// };

// 3.Optimal
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();

        if(n!=t.size()) return false;
        int freq[26] = {0};

        for(auto x:s)
        {
            freq[x-'a']++;
        }
        for(auto x:t)
        {
            freq[x-'a']--;
        }
        for(int x:freq)
        {
            if(x!=0) return false;
        }
        return true;
    }
};