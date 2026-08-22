// // 1.Brute
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if (s.size() != goal.size()) return false;
//         int n = s.size();
//         for(int i=0;i<n;i++)
//         {
//             if(s.compare(goal)==0) return true;
//             char temp = s[0];
//             s.erase(0,1);
//             s+= temp;
//         }
//         return false;
//     }
// };

// 2.Optimal
// Goal if present must be found in s+s;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string doubled = s+s;
        return doubled.find(goal) != string::npos;
        // string::npos means "not found" when used with string searching functions like find().
    }
};