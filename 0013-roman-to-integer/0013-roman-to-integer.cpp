// class Solution {
// public:
//     int romanToInt(string s) {
//         int ans=0;
//         for(int i=0;i<s.size();)
//         {
//             if(s[i]=='I' && (s[i+1]!='V' && s[i+1]!='X')) {ans+= 1; i++;}
//             else if(s[i]=='X' && (s[i+1]!='L' && s[i+1]!='C')) {ans+= 10; i++;}
//             else if(s[i]=='C' && (s[i+1]!='D' && s[i+1]!='M')) {ans+= 100; i++;}
//             else if(i<s.size() && s[i]=='I' && s[i+1]=='V' ) {ans+= 4; i+=2;}
//             else if(i<s.size() && s[i]=='I' && s[i+1]=='X') {ans+= 9; i+=2;}
//             else if(i<s.size() && s[i]=='X' && s[i+1]=='L' ) {ans+= 40; i+=2;}
//             else if(i<s.size() && s[i]=='X' && s[i+1]=='C' ) {ans+= 90; i+=2;}
//             else if(i<s.size() && s[i]=='C' && s[i+1]=='D' ) {ans+= 400; i+=2;}
//             else if(i<s.size() && s[i]=='C' && s[i+1]=='M' ) {ans+= 900; i+=2;}
        
//             else if(s[i]=='V') {ans+= 5; i++;}
//             else if(s[i]=='L') {ans+= 50; i++;}
//             else if(s[i]=='D') {ans+= 500; i++;}
//             else if(s[i]=='M') {ans+= 1000; i++;}
        
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();

        unordered_map<char,int> mp = 
        {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int ans=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(mp[s[i]] < mp[s[i+1]]) ans-= mp[s[i]];
            else ans+= mp[s[i]];
        }
        return ans + mp[s[n-1]]; // Last left value is added
    }
};