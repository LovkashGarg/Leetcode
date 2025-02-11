class Solution {
public:
vector<int>dirrow={-1,0,1,0};
vector<int>dircol={0,1,0,-1};

int maxi=0;
    void solve(int i,int j, int m,int n, vector<vector<int>> &dp,vector<vector<int>>& matrix){
       
        int curr=1;
        for(int k=0;k<4;k++){
            int newrow=i + dirrow[k];
            int newcol= j + dircol[k];
          
            if(newrow >=0 && newrow < m && newcol>=0 && newcol < n && matrix[newrow][newcol] >matrix[i][j] ){
               if(dp[newrow][newcol]!=-1){
                    curr=max(curr,dp[newrow][newcol]+1); // Here we included this length 
                }
                else{
                  solve(newrow,newcol, m,n, dp,matrix);
                  curr=max(curr,dp[newrow][newcol]+1);
                }
            }
        }

        dp[i][j]=max(curr,dp[i][j]);
        maxi= max(maxi,dp[i][j]);
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
int m=matrix.size();
int n=matrix[0].size();
      vector<vector<int>> dp(m,vector<int>(n,-1));

      // I need to find longest path for each and everyone 
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
             if(dp[i][j]==-1){ 
                solve(i,j,m,n, dp,matrix);
             }    
        }
      }

      return maxi;
    }
};