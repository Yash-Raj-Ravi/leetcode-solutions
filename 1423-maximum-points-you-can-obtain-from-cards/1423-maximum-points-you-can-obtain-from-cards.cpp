// 1.Brute
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int maxScore=0;
        int score=0;
        for(int i=0;i<k;i++)
        {
            score+= cardPoints[i];
        }
        int left=k-1;
        int right=n-1;
        maxScore=score;
        while(left>=0)
        {
            score-= cardPoints[left];
            score+= cardPoints[right];
            maxScore= max(score,maxScore);
            left--;
            right--; 
        }
    
     return maxScore;
    }
};

// 2.Optimal
// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
        
//     }
// };