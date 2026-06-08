// // 1.Brute
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int rows=matrix.size();
//         int cols=matrix[0].size();

//         for(int i=0;i<rows;i++)
//         {
//             for(int j=0;j<cols;j++)
//             {
//                 if(matrix[i][j]==target)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// 2.Better
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<rows;i++)
        {
            if(matrix[i][0]<= target && target<= matrix[i][cols-1])
            {
                int low = 0;
                int high = cols-1;
                while(low<=high)
                {
                    int mid = low + (high-low)/2;
                    if(matrix[i][mid]==target)
                    {
                        return true;
                    }
                    else if(matrix[i][mid]<target)
                    {
                        low=mid+1;
                    }
                    else
                    {
                        high=mid-1;
                    }
                }
            }
        }
        return false;
    }
};



// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//     }
// };