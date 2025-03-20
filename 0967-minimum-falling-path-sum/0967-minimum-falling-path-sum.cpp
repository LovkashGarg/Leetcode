class Solution {
public:

   int solve(int row_index,int col_index, int n, vector<vector<int>>&dp ,vector<vector<int>>& matrix  ){
     
    if(row_index>=n){
        return 0;
    }

     if(dp[row_index][col_index] !=1e9){
        return dp[row_index][col_index];
     }

    int bottom= matrix[row_index][col_index]+ solve(row_index+1,col_index,n,dp,matrix);
    int left_bottom= INT_MAX;
    if(col_index-1>=0){
    left_bottom= matrix[row_index][col_index]+ solve(row_index+1,col_index-1,n,dp,matrix);
    }

    int right_bottom=INT_MAX;
    if(col_index+1<n){
    right_bottom= matrix[row_index][col_index]+ solve(row_index+1,col_index+1,n,dp,matrix);
    }


    return dp[row_index][col_index]= min({left_bottom, bottom, right_bottom});

   }
    int minFallingPathSum(vector<vector<int>>& matrix) {

       int n=matrix.size();

       vector<vector<int>>dp(n,vector<int>(n,1e9));

int ans=INT_MAX;
       // Here starting point can be various
       for(int i=0;i<n;i++){
       ans=min(ans, solve(0,i,n,dp,matrix)); 
       }

       return ans;
    }
};