class Solution {
public:
   bool solve(int i,int j, int main, int m,int n, string &s1,string &s2,string &s3,vector<vector<int>>&dp){
      
      bool  flag=false;

      // matlab dono ka koi bhi character bhi nhi chutna chahiye 
      if(main==s3.size() && i== m && j==n){
        return true;
      }
     if(dp[i][j]!=-1){
        return dp[i][j];
     }

      if(i<m && j<n){
           
          if(s1[i]==s3[main] && s2[j]!=s3[main]){
           flag=flag || solve(i+1,j,main+1,m,n,s1,s2,s3,dp);
          }
          else if(s2[j]==s3[main] && s1[i]!=s3[main]){
           flag=flag || solve(i,j+1,main+1,m,n,s1,s2,s3,dp);
          }
          else if(s2[j]==s3[main] && s1[i]==s3[main]){
           flag=flag || solve(i+1,j,main+1,m,n,s1,s2,s3,dp) || solve(i,j+1,main+1,m,n,s1,s2,s3,dp) ;
          }
          // means not equal 
          else{
            return dp[i][j]= false;
          }
      }
      else if(i<m){
          if(s1[i]==s3[main] ){
           flag=flag || solve(i+1,j,main+1,m,n,s1,s2,s3,dp);
          }
          else{
            return dp[i][j]= false;
          }
      }
      else if(j<n){
        if(s2[j]==s3[main] ){
           flag=flag || solve(i,j+1,main+1,m,n,s1,s2,s3,dp);
          }
          else{
            return dp[i][j]= false;
          }
      }

      return dp[i][j]=flag;
   }
    bool isInterleave(string s1, string s2, string s3) {
        
        int i=0;
        int j=0;
        int main=0;
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(i,j,main,m,n,s1,s2,s3,dp);
    }
};