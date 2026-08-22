class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.size();)
        {
            if(s[i]=='I' && (s[i+1]!='V' && s[i+1]!='X')) {ans+= 1; i++;}
            else if(s[i]=='X' && (s[i+1]!='L' && s[i+1]!='C')) {ans+= 10; i++;}
            else if(s[i]=='C' && (s[i+1]!='D' && s[i+1]!='M')) {ans+= 100; i++;}
            else if(s[i]=='I' && s[i+1]=='V' &&  i<s.size() ) {ans+= 4; i+=2;}
            else if(s[i]=='I' && s[i+1]=='X' &&  i<s.size() ) {ans+= 9; i+=2;}
            else if(s[i]=='X' && s[i+1]=='L' &&  i<s.size() ) {ans+= 40; i+=2;}
            else if(s[i]=='X' && s[i+1]=='C' &&  i<s.size() ) {ans+= 90; i+=2;}
            else if(s[i]=='C' && s[i+1]=='D' &&  i<s.size() ) {ans+= 400; i+=2;}
            else if(s[i]=='C' && s[i+1]=='M' &&  i<s.size() ) {ans+= 900; i+=2;}
        
            else if(s[i]=='V') {ans+= 5; i++;}
            else if(s[i]=='L') {ans+= 50; i++;}
            else if(s[i]=='D') {ans+= 500; i++;}
            else if(s[i]=='M') {ans+= 1000; i++;}
        
        }
        return ans;
    }
};