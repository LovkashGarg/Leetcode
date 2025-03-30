class Solution {
public:
     int solve(int index, int buy, vector<int>&prices, int n,vector<vector<int>>&dp){

    if(index==n){
        return 0;
    }
     if(dp[index][buy]!=INT_MIN){
        return dp[index][buy];
     }

     int maxprofit=0;

     if(buy==0){
        int profit1= -prices[index] + solve(index+1, 1,prices,n,dp);
        int profit2= solve(index+1, 0, prices,n,dp);
        maxprofit=max({profit1,profit2,maxprofit});
     }
     else{
        int profit1= prices[index] + solve(index+1, 0, prices,n,dp);
        int profit2= solve(index+1, 1, prices,n,dp);
          maxprofit=max({profit1,profit2,maxprofit});
     }
     return dp[index][buy]=maxprofit;

     }


    int maxProfit(vector<int>& prices) {
        
        // since we can hold one stock so therefore we store it in a variable whether we can buy or not
        int n=prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,INT_MIN));
        return solve(0,0,prices,n,dp);
    }
};