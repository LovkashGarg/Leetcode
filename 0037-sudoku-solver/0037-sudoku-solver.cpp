class Solution {
public:
   bool issafe(char k,int i,int j,vector<vector<char>>&board){

    // check if it is safe  for  col in which it is present 
    for(int row=0;row<9;row++){
         if(board[row][j]==k){
            return false;
         }
    }

    for(int col=0;col<9;col++){
        if(board[i][col]==k){
            return false;
        }
    }

    // check in the 3 *3 it is present 
    int rowmatrix3_3index= i/3;
    int colmatrix3_3index=j/3;
// cout<<"start"<<endl;
    for(int l=0;l<3;l++){
        for(int t=0;t<3;t++){
            if(board[rowmatrix3_3index*3+l][colmatrix3_3index*3+t]==k){
                return false;
            }
        }
        cout<<endl;
    }
    return true;
   }
bool solvesudoku(vector<vector<char>> &board, int i, int j)
{
    if(i==9) return true;
    if(j==9) return solvesudoku(board, i+1, 0);
    if(board[i][j] != '.') return solvesudoku(board, i, j+1);

    for(char c='1'; c<='9'; c++)
    {
        if(issafe( c,i, j ,board))
        {
            board[i][j] = c;
            if(solvesudoku(board, i, j+1)) return true;
            board[i][j] = '.';
        }
    }
        
    return false;
}

    void solveSudoku(vector<vector<char>>& board) {
        
      solvesudoku(board,0,0);
    }
};