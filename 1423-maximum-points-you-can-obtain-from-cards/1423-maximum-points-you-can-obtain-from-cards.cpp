// // 1.Brute
// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n= cardPoints.size();
//         int maxScore=0;
//         for(int i=0;i<=k;i++) // Loop will run till k included since for k, we have k+1 ways of taking cards.
//         {
//             int score=0;
//             // Cards taken from front
//             for(int j=0;j<i;j++)
//             {
//                 score+= cardPoints[j];
//             }
//             // Cards taken from back
//             for(int j=0;j<k-i;j++)
//             {
//                 score+= cardPoints[n-1-j];
//             }
//             maxScore=max(maxScore,score);// maxScore updated after cards have been taken from front and back combining to k number of cards.
//         }
//         return maxScore;
//     }
// };

// 2.Optimal
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
