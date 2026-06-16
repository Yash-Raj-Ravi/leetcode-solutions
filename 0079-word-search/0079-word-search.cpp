class Solution {
public:
 bool dfs(vector<vector<char>>& board, string &word,int i,int j,int idx)
 {
    int rows=board.size();
    int cols=board[0].size();
    if(idx==word.size()) // Means if search reaches past end of word means word is found.
    {
        return true;
    }

    if(i<0 || j<0 || i>=rows || j>=cols|| board[i][j]!=word[idx]) {return false;}
    // Mark current chosen character as visited to avoid resuing it.
    char temp = board[i][j];
    board[i][j]='*';
    // Check all directions for searching the word
    bool found = dfs(board,word,i+1,j,idx+1) || dfs(board,word,i-1,j,idx+1)||dfs(board,word,i,j+1,idx+1)||dfs(board,word,i,j-1,idx+1) ;

    // Restore the visited marked charater if word not found yet (Backtracking)
    board[i][j] = temp;

    return found;
 }

    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(dfs(board,word,i,j,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};