class Solution {
public:
int mod=1e9 +7;

   long long total=0;
    vector<int>dirrow={-1,0,1,0};
    vector<int>dircol={0,1,0,-1};

    void solve(int i,int j, int m,int n, vector<vector<int>> &grid,vector<vector<int>>&dp){

       if (dp[i][j] != -1) return ;
      
       long long curr=1;  // for single node 
         // Here we have to traverse 
         for(int k=0;k<4;k++){
            int newrow= i+ dirrow[k];
            int newcol= j+ dircol[k];

            if(newrow>=0 && newrow<m && newcol >=0 && newcol <n && grid[newrow][newcol] >grid[i][j]  ){
            
                if(dp[newrow][newcol]!=-1){
                   curr=( curr + dp[newrow][newcol])%mod;
                }
                else {
                  solve(newrow,newcol,m,n,grid,dp);
                  curr=( curr + dp[newrow][newcol])%mod;
                }

            }
         }

         dp[i][j]= (curr%mod);
         total=(total+ dp[i][j])%mod;

    }
    int countPaths(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1 ){
 solve(i,j,m,n,grid,dp);
                }
            }
        }


        return total%mod;

    }
};