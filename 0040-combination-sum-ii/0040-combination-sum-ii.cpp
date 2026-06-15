class Solution {
public:

void helper(int index,vector<int>& candidates, int target, vector<vector<int>> &ans,vector<int> &arr)
{
     if(target==0)
    {
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<candidates.size();i++)
    {
    // consider only the 1st element and skip its duplicates.
    if(i>index && candidates[i]==candidates[i-1]) continue;

    // Since candidates is sorted so if current element is greater than target then all further elements will also be greater so break.
    if(target<candidates[i]) break;


    arr.push_back(candidates[i]);
    helper(i+1,candidates,target-candidates[i],ans,arr);
    arr.pop_back();
    }

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(),candidates.end());// Sorting is essential so that all duplicates come adjacent thus it becomes easier to avoid them.
        helper(0,candidates,target,ans,arr);
        return ans;
    }
};