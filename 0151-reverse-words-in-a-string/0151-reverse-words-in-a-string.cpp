// // 1.Brute
// class Solution {
// public:
//     string reverseWords(string s) {
//         vector<string> words; // To store list of words
//         string word = "";     // To collect each valid word
//         int n = s.size();

//         for (int i = 0; i < n; i++) {
//             if (s[i] != ' ')
//                 word.push_back(s[i]);
//             else if (!word.empty()) // If space encountered
//             {
//                 words.push_back(word);
//                 word = ""; // Reset the word for next word formation
//             }
//         }
//         if (!word.empty())
//             words.push_back(word); // For last word

//         reverse(words.begin(), words.end());
//         string ans = "";
//         for (int j = 0; j < words.size(); j++) {
//             ans += words[j];
//             // Add a space if it's not the last word
//             if (j < words.size() - 1) {
//                 ans += " ";
//             }
//         }

//         return ans;
//     }
// };

// 2.Optimal
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        int i = n - 1;
        while (i >= 0) {

            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;
            int end = i;

            while (i >= 0 && s[i] != ' ')
                i--;

            string word = s.substr(i + 1, end - i);

            if (!ans.empty()) {
                ans += ' ';
            }
            ans += word;
        }
        return ans;
    }
 };