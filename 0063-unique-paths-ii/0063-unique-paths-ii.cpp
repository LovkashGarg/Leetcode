class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int i,int j,int m ,int n,vector<vector<int>>&dp){
        if(i == m-1 && j==n-1){
            cout<<i<<j<<endl;
            return 1;
        }
        int right=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j+1 <n && obstacleGrid[i][j+1]==0){
         right= solve(obstacleGrid,i,j+1,m,n,dp);
        }
        int down=0;
        if(i+1<m && obstacleGrid[i+1][j]==0){
        down=solve(obstacleGrid,i+1,j,m,n,dp);
        }
        dp[i][j]= right + down;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int ans=0;
        if(m==1  &&  n==1){
            if(obstacleGrid[0][0]==0){
                return 1;
            }
            return 0;
        }
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       return solve(obstacleGrid,0,0,m,n,dp); 

    }
};