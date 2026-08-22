class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start=0;
        int maxLen=1;

    for(int i=0;i<n;i++){
        // Odd center palindrome
        int l=i; int r=i;
        while(l>=0 && r<n && s[l]==s[r])
        {
            if(r-l+1 > maxLen) {
                start = l;
                maxLen = max(maxLen,r-l+1);
            }
            l--;r++;
        }

        // Even center palindrome
        l=i; r=i+1;
        while(l>=0 && r<n && s[l]==s[r])
        {
            if(r-l+1 > maxLen) {
                start = l;
                maxLen = max(maxLen,r-l+1);
            }
            l--;r++;
        }

    }
       return s.substr(start,maxLen);
    }
};