class Solution {
public:
    bool ans=false;
    void solve(int index,int x,int y,int m,int n,vector<vector<char>>& board, string word,vector<vector<int>>&visited){

        visited[x][y]=1;
      
        if(index==word.size()){
            // cout<< x<<y<< index<<endl;
            ans=true;
            return;
        }

        vector<int>dirrow={-1,0,1,0};
        vector<int>dircol={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newrow=dirrow[i]+ x;
            int newcol=dircol[i]+ y;
              
            if(newrow>=0 && newrow <m && newcol>=0 && newcol<n  && !visited[newrow][newcol] ){

                 if(board[newrow][newcol] ==word[index]){
                    solve(index+1,newrow,newcol,m,n,board,word,visited);
                 }
                 
            }
        }
        // backtracking
        visited[x][y]=0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int index=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==word[index]){
        //    cout<<i<<j<<endl;
        solve(index+1,i,j,m,n,board,word,visited);
            }
        }
       }

        return ans;
    }
};