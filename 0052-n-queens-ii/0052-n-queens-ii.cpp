class Solution {
public:
    int count=0;
    bool issafe(vector<vector<int>>&board,int row,int col,int n){

        // check the before row of each col 
        for(int i=0;i<col;i++){
            if(board[row][i]==1){
                return false;
            }
        }

        // check upper diagonal 
        for(int x=row, y=col;x>=0 && y>=0 ;x--,y--){
            if(board[x][y]==1){
                return false;
            }
        }
        //check lower triangle 
        for(int x=row, y=col;x<n && y>=0 ;x++,y--){
            if(board[x][y]==1){
                return false;
            }
        }

        return true;
    }

    void solve(vector<vector<int>>&board,int col,int n){
       if(col==n){
        count++;
        return ;
       }
     
     // try to check every row 

       for(int row=0;row<n;row++){
           if(issafe(board,row,col,n)){
            board[row][col]=1;
            solve(board,col+1,n);
            board[row][col]=0;
           }
       }
    }

    int totalNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        solve(board,0,n);
        return count;
    }
};