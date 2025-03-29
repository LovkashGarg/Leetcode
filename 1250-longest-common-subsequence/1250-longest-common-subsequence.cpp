class Solution {
public:
    int solve(int i,int j, int m, int n , string & text1 , string & text2 , vector<vector<int>> & dp ){
         
         // agar match ho rha to age jao varna i ko agge badao or j ko bda ke 
         if(i==m || j==n){
            return 0;
         }

         if(dp[i][j]!=-1){
            return dp[i][j];
         }
         if(text1[i]== text2[j]){
            return dp[i][j]=1 + solve(i+1,j+1, m,n,text1,text2,dp);
         }
         else{
            return dp[i][j]= max(solve(i+1, j , m,n ,text1, text2, dp), solve(i, j+1, m,n ,text1, text2, dp));
         }


    }

    int longestCommonSubsequence(string text1, string text2) {

        
        // Here  I need to check for the longest commmon subsequence 
        int m= text1.size();
        int n= text2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
       return  solve(0,0, m,n ,text1,text2,dp);
         
    }

};