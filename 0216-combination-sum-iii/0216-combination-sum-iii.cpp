class Solution {
public:

void helper(int index, vector<vector<int>> &ans,vector<int> &comb,int k,int n)
{
    if(k==0)
    {
        if(n==0)
        {ans.push_back(comb);}
        return;
    }

    if(n<0) return;
        for(int i=index;i<10;i++)
        {
        if(i<=n){
         comb.push_back(i);
         helper(i+1,ans,comb,k-1,n-i);
         comb.pop_back();
        }
        else
         break;
        
        }
        
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        helper(1,ans,comb,k,n);
        return ans;
    }
};