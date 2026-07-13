class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i=0;

        // 1. Push intervals completely before newInterval to ans
        while(i < n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        // 2. Merge overlapping intervals then push the mergen newInterval
        while(i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);

        // 3. Push the remaining non-overlapping intervals
        while(i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
      
    return ans;
    }
};