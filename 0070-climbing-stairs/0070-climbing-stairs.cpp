class Solution {
public:
    int dpclimb(int n, vector<int>& dp){

      if(n<=2){
        dp[n]= n;
        return dp[n];
        } 
        if(dp[n]!=-1){
            return dp[n];
        }
       return  dp[n]=dpclimb(n-1,dp)+ dpclimb(n-2,dp);
   
    }
    int climbStairs(int n) {
       
vector<int> dp(n+1,-1);
        return dpclimb(n,dp);
    }
};