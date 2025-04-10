class Solution {
public:
   int solve(int i , int j1, int j2 , int m , int n , vector<vector<int>>&grid ,vector<vector<vector<int>>>&dp){
    if(i==m){
        return 0;
    }

    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }

    // I have three option 
    int maxi= 0;
    if(j1!=j2){
      maxi+=grid[i][j1] + grid[i][j2]  ;
    }
    else{
      maxi+=grid[i][j1]  ;
    }

   int ans=0;
    for(int k1=-1;k1<=1;k1++){
        for(int k2=-1;k2<=1;k2++){
           if(j1+k1 >=0 && j2 + k2>=0 && j1+ k1 <n && j2+k2<n){
             ans=max(ans ,maxi + solve(i+1, j1+k1 , j2+k2, m,n,grid,dp));
           }
        }
    }

    return dp[i][j1][j2]=ans;

   }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return solve(0,0,n-1,m,n,grid,dp);
    }
};