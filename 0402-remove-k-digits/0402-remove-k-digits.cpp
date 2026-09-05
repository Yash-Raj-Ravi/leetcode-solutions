class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans="";
        int n = num.size();
        for(int i=0;i<n;i++){

            while(!st.empty() && k!=0 && num[i]-'0'<st.top()-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
                st.pop();
                k--; 
            }

        if(st.empty()) return "0";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        
        while(ans.size()!=0 && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.empty()) return "0";
        return ans; 
    }
};

