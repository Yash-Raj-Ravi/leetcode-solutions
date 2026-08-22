class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0};
        for(char c:s)
        {
            freq[c]++;
        }
        vector<pair<char,int>> P;

        for(int i=0;i<256;i++)
        {
            if(freq[i]>0)
            {
                P.push_back({(char)i,freq[i]});
            }
        }

        sort(P.begin(),P.end(),[](auto &a, auto &b){
            return a.second > b.second;
        });

        string ans="";
        for(auto &p:P)
        {
            ans+= string(p.second,p.first);
        }

        return ans;
    }
};