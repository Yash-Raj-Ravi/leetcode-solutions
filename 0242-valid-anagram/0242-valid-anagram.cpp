// 1.Brute
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t) return true;
        return false;
    }
};


// class Solution {
// public:
//     bool isAnagram(string s, string t) {
        
//     }
// };