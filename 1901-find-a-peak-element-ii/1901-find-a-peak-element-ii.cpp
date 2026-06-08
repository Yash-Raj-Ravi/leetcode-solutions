// Optimal
class Solution {
public:
  int findrow(vector<vector<int>> &mat,int col)
  {
    int rows=mat.size();
    int index=-1;
    int maxval=INT_MIN;
    for(int i=0;i<rows;i++)
    {
        if(mat[i][col]>maxval)
        {
            maxval = mat[i][col];
            index=i;
        }
    }
    return index;
  }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();

        int low=0;
        int high=cols-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int row_with_largest_val = findrow(mat,mid);
            // Determine the elements to the left and right of 
            // the middle element in the found row
            int left = (mid-1)>0 ? mat[row_with_largest_val][mid-1]:INT_MIN;
            int right = (mid+1)<cols ? mat[row_with_largest_val][mid+1]:INT_MIN;

            if(mat[row_with_largest_val][mid] > left && mat[row_with_largest_val][mid] > right)
            {
                return {row_with_largest_val,mid};
            }
            else if(mat[row_with_largest_val][mid] < left)
            {
                high=mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
    return {-1,-1};
    }
};