// // 1.Brute
// // What does the string constructor do?

// std::string has a constructor:

// string(iterator first, iterator last);

// which copies everything in the range [first, last).

// So:

// string row(board[i].begin(), board[i].end());

// becomes:

// ".Q.."
// class Solution {
// public:

// // Check if Queen can be inserted safely.
// bool isSafe(int row, int col,vector<vector<char>> &board,int n)
// {
//     // Ensure that no queen lies vertically 
//     // Going row wise , we need not check horizontally since we are placing one queen per row.
//     for(int i=0;i<row;i++)
//     {
//         if(board[i][col]=='Q') return false;
//     }
//     // Ensure No queen lies at top-left diagonal
//     for(int i=row,j=col;i>=0 && j>=0;i--,j--)
//     {
//         if(board[i][j]=='Q') return false;
//     }
//      // Ensure No queen lies at top-right diagonal
//      for(int i=row,j=col;i>=0 && j<n;i--,j++)
//     {
//         if(board[i][j]=='Q') return false;
//     }
//     return true;
// }

// // Backtracking function to place queens row by row
// void solve(int row, vector<vector<string>> &ans,vector<vector<char>> &board,int n)
// {
//     // If queen placing reaches last row means one valid positioned board is found.
//     if(row==n)
//     {
//        vector<string> temp;
//        for(int i=0;i<n;i++){
//        string s(board[i].begin(),board[i].end());
//        temp.push_back(s);
//        }
//     ans.push_back(temp);
//     return;
//     }

//     // Try placing queen in all columns of current row
//     for(int col=0;col<n;col++)
//     {
//         if(isSafe(row,col,board,n))
//         {
//             board[row][col]='Q';

//             solve(row+1,ans,board,n); // Recurse for next row
//              // Backtrack and remove queen
//             board[row][col]='.';
//         }
       
//     }
   
// }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<vector<char>> board(n,vector<char> (n,'.'));
//         // start from 1st row (index 0)
//         solve(0,ans,board,n);
//         return ans;
//     }
// };


// So far isSafe is taking O(n) time so we will try to reduce it to O(1) as further optimization.


// 2.Optimal
class Solution {
public:

void solve(int row,int n, vector<int> &column,
        vector<int> &lowerdiagonal,
        vector<int> &upperdiagonal, vector<vector<string>> &ans,vector<string> &board)
        {

            if(row==n)
            {
                ans.push_back(board);return;
            }

            // check if safe or not
            for(int col=0;col<n;col++){
            if(column[col]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[n-1 + col-row]==0)
            {
                board[row][col]='Q';
                // mark the corresponding neighbours unsafe
                column[col]=1;
                lowerdiagonal[row+col]=1; upperdiagonal[n-1 + col-row]=1;
                solve(row+1,n,column,lowerdiagonal,upperdiagonal,ans,board);// Recurse

                board[row][col]='.';//Backtrack;
                column[col]=0;
                lowerdiagonal[row+col]=0; upperdiagonal[n-1 + col-row]=0;
            }
            }

        }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<int> column(n,0);
        vector<int> lowerdiagonal(2*n-1,0);
        vector<int> upperdiagonal(2*n-1,0);
        solve(0,n,column,lowerdiagonal,upperdiagonal,ans,board);
        return ans;
    }
};