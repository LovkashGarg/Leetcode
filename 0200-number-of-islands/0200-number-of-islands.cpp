class Solution {
public:
vector<int>rows={-1,0,1,0};
vector<int>cols={0,1,0,-1};

void solve(vector<vector<int>>&visited,vector<vector<char>>& grid,  int i,int j,int m,int n){
    // 
    visited[i][j]=1;
    for(int k=0;k<4;k++){
        int newrow=rows[k]+ i;
        int newcol=cols[k] + j;

        if(newrow>=0 && newrow<m && newcol >=0 && newcol<n && visited[newrow][newcol]==0 && grid[newrow][newcol] =='1'){

 solve(visited,grid,newrow,newcol,m,n);
        }
    }
    
}
    int numIslands(vector<vector<char>>& grid) {
        
int m=grid.size();
int n=grid[0].size();
int count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(!visited[i][j] && grid[i][j]=='1'){
                solve(visited,grid,i,j,m,n);
                count++;
              }
            }
        }
        
        return count;
    }
};