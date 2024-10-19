class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
    
    // check for all four direction 
      grid[i][j]=-1;
    if(i+1 <n && grid[i+1][j]==1 ){
        dfs(grid,i+1,j,n,m);
    }
    if(j+1<m && grid[i][j+1]==1){
        dfs(grid,i,j+1,n,m);
    }
    if(i-1 >=0 &&  grid[i-1][j]==1 ){
        dfs(grid,i-1,j,n,m);
    }
    if(j-1>=0 && grid[i][j-1]==1){
         dfs(grid,i,j-1,n,m);
    }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        // we need to check at boundary only if the one that are present 
        // fist column
        int n=grid.size();
        int m=grid[0].size();
        int j=0;
        for(int i=0;i<grid.size();i++){
             if(grid[i][j] ==1 ){
                dfs(grid,i,j,n,m);
             }
        }
        j=m-1;
        for(int i=0;i<grid.size();i++){
             if(grid[i][j] ==1 ){
                dfs(grid,i,j,n,m);
             }
        }
        int i=0;
        for(int j=0;j<m;j++){
             if(grid[i][j] ==1 ){
                dfs(grid,i,j,n,m);
             }
        }
        i=n-1;
        for(int j=0;j<m;j++){
             if(grid[i][j] ==1 ){
                dfs(grid,i,j,n,m);
             }
        }
        int count=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                count++;
            }
            // cout<<grid[i][j]<<" ";
        }
        cout<<endl;
     } 
     return count; 
    }

};