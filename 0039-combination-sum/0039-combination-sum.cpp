class Solution {
public:
   
    void combinations(int index,vector<int>& candidates, int target, vector<int> &arr,vector<vector<int>> &ans) {

        if(target==0) 
        {
        ans.push_back(arr);
        return;
        }

        if(index==candidates.size() || target<0) return;
        
        // Include current element and proceed
        arr.push_back(candidates[index]);
        combinations(index,candidates,target-candidates[index],arr,ans);
        arr.pop_back(); // Backtrack before proceeding further
        // Exclude current element and proceed
        combinations(index+1,candidates,target,arr,ans);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        combinations(0,candidates,target,arr,ans);
        return ans;
    }
};