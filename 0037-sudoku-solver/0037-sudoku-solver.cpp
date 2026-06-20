class Solution {
public:
bool isvalid(int row,int col,char k,vector<vector<char>>& board)
{
    for(int idx=0;idx<9;idx++)
    { 
    if(board[row][idx]==k)
       return false;
    if(board[idx][col]==k)
       return false;
    
    if(board[3*(row/3) + idx/3][3*(col/3) + idx%3]==k)
       return false;
    }
    return true;
}
bool solver(vector<vector<char>>& board)
{
     for(int i=0;i<9;i++)
     {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                for(char k='1';k<='9';k++)
                {
                  if(isvalid(i,j,k,board))
                    {
                    board[i][j]=k;
                    if(solver(board))
                    {
                        return true;
                    }
                    board[i][j]='.';
                    }
                }
             return false;
            }
        }
     }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
       solver(board);
    }
};