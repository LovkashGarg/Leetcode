class Solution {
public:
    bool issafe(vector<vector<int>>&board,int row,int col,int n,vector<vector<string>>&ans){

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
     void addSolution(vector<vector<int>>&board,vector<vector<string>>&ans,int n){
        vector<string>temp;
        for(int i=0;i<n;i++){
            string tem;
            for(int j=0;j<n;j++){
                
                if(board[i][j]==0){
                  tem+='.';
                }
                else{
                    tem+='Q';
                }
            }
            temp.push_back(tem);
        }
        ans.push_back(temp);
     }
    void solve(vector<vector<int>>&board,int col,int n,vector<vector<string>>&ans){
       if(col==n){
        addSolution(board,ans,n);
        return ;
       }
     
     // try to check every row 

       for(int row=0;row<n;row++){
           if(issafe(board,row,col,n,ans)){
            board[row][col]=1;
            solve(board,col+1,n,ans);
             board[row][col]=0;
           }
       }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<string>>ans;
        solve(board,0,n,ans);
        return ans;
    }
};