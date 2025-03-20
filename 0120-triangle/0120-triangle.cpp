class Solution {
public:
int solve(int row_index,int col_index,int n, vector<vector<int>>&dp, vector<vector<int>> &triangle){

    if(row_index>=n){
        return 0;
    }
    if(dp[row_index][col_index]!=-1){
        return dp[row_index][col_index];
    }

    // I have two choices 
    int bottom = triangle[row_index][col_index]+ solve(row_index+1,col_index,n,dp,triangle);
    int right_bottom=triangle[row_index][col_index]+ solve(row_index+1,col_index+1,n,dp,triangle);

    return dp[row_index][col_index]= min(bottom, right_bottom);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // I have to start form index 0
        int n=triangle.size(); 
        vector<vector<int>>dp(n);
        for(int i=0;i<n;i++){
            dp[i].resize(triangle[i].size(),-1);
        }
        return solve(0,0, n,dp,triangle);
    }
};