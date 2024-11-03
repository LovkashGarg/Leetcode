class Solution {
public:
void dfs(int i,int j, int n,int m, vector<vector<char>>& board,vector<vector<int>> &visited){

     visited[i][j]=1;
     if(i>=0 && i+1 <n && j>=0 &&  j<m &&visited[i+1][j]!=1 && board[i+1][j]=='X' ){
        dfs(i+1,j,n,m,board,visited);
     }
     if(i <n && j+1<m &&visited[i][j+1]!=1 && board[i][j+1]=='X' ){
        dfs(i,j+1,n,m,board,visited);
     }
     if(i-1>=0 && j<m &&visited[i-1][j]!=1 && board[i-1][j]=='X' ){
        dfs(i+1,j,n,m,board,visited);
     }
     if(i <n && j-1>=0 &&visited[i][j-1]!=1 && board[i][j-1]=='X' ){
        dfs(i+1,j,n,m,board,visited);
     }

}
    int countBattleships(vector<vector<char>>& board) {
  int n=board.size();
      int m=board[0].size();
      vector<vector<int>>visited(n,vector<int>(m,0));
    
      int count=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(visited[i][j]!=1 && board[i][j]=='X' ){
            dfs(i,j,n,m,board,visited);
            count++;
          }
        }
      }
      return count;
    }
};