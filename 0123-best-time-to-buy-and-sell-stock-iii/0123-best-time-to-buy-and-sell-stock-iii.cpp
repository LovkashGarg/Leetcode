class Solution {
public:
    int solve(int index, int buy , vector<int> & prices, int n, int k,vector<vector<vector<int>>>&dp){

        if(index==n){
            return 0;
        }

        if(k==0){
            return 0;
        }

        if(dp[index][buy][k]!=-1){
            return dp[index][buy][k];
        }

 int maxprofit=0;
        if(buy==0){
          maxprofit=max(0, max(-prices[index] + solve(index+1, 1,prices,n,k,dp) , solve(index+1, 0, prices,n,k,dp)));
        }
        else{
            maxprofit=max(0,max(prices[index] + solve(index+1, 0,prices,n,k-1,dp) , solve(index+1, 1, prices,n,k,dp)));
        }

        return  dp[index][buy][k]= maxprofit;

    }
    int maxProfit(vector<int>& prices) {

      
      int n = prices.size();
      vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
      return solve(0,0,prices,n,2,dp);
    }
};