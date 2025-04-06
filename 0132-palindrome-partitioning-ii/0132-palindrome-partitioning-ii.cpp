class Solution {
public:
    bool check (int start ,int end , string &s){
         int len = end- start +1;
         int i=start;
         int j= end;

         while(i<=j){
           if(s[i]==s[j]){
            i++;
            j--;
           }
           else{
            return false;
           }
         }

         return true;
    }
   int solve(int i , int j , string & s,vector<vector<int>> & dp){

    if(i>j){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int count =INT_MAX;

    for(int k=i ;k<=j;k++){

        // when k == j means no partitioning already palindrome 
         if(check(i,k,s)){
         count = min(count , 1 + solve(k+1,j,s,dp));
         }
         
    }

    return dp[i][j]=count;
   }
    int minCut(string s) {
        
        // first I   have to define all the palindrome 
        int n= s.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1,-1));
        return solve(0,n-1,s,dp )-1;
    }
};