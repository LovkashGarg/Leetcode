class Solution {
public:

    int solve_tab( int n, vector<int>&prices){
      
      // for base case 
      vector<vector<int>>dp(n+1, vector<int>(2,0));

      // I have to shift the index 
      // means for -1 index max value is 0
      dp[n][0]=0;
      dp[n][1]=0;


      for(int i=n-1;i>=0;i--){
        // buy value 
        for(int j=0;j<=1;j++){

           if(j==0){
            dp[i][j]=max(dp[i][j], max(-prices[i] + dp[i+1][1-j], dp[i+1][j]));
           }
           else{
            dp[i][j]=max(dp[i][j], max(prices[i] +  + dp[i+1][1-j] , dp[i+1][j]));
           }

        }
       
      }

// max profit with buying allowed 
      return dp[0][0];

    }

    int maxProfit(vector<int>& prices) {
        
        // since we can hold one stock so therefore we store it in a variable whether we can buy or not
        int n=prices.size();
        return solve_tab(n,prices);
    }
};