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

    bool solveSudokuHelper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (issafe(k, i, j, board)) {
                            board[i][j] = k; // Place the digit
                            
                            // Recursively solve the next cells
                            if (solveSudokuHelper(board)) {
                                return true; // Stop if a solution is found
                            }
                            
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    
                    return false; // No valid number found for this cell
                }
            }
        }
        return true; // Solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        
      solveSudokuHelper(board);
    }
};