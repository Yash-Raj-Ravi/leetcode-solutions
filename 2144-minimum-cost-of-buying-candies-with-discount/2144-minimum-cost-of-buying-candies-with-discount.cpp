class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        reverse(cost.begin(),cost.end());
        int minCost=0;
        for(int i=0;i<n;i++)
        {
            if((i+1)%3!=0 && i<n){
            minCost+= cost[i]; 
            }
        }
        return minCost;
    }
};