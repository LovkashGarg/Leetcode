class Solution {
public:

    int solve_tab( int n, vector<int>&prices){
      
  

      // I have to shift the index 
      // means for -1 index max value is 0
    
     vector<int>curr(2,0);
     vector<int>prev(2,0);
    //   prev[0]=0;
    //   prev[1]=0;

      for(int i=n-1;i>=0;i--){
        // buy value 
        for(int j=0;j<=1;j++){

           if(j==0){
            curr[j]=max(curr[j], max(-prices[i] + prev[1-j], prev[j]));
           }
           else{
            curr[j]=max(curr[j], max(prices[i] +  prev[1-j] , prev[j]));
           }

        }

        prev=curr;
        
      }

// max profit with buying allowed 
      return prev[0];

    }

    int maxProfit(vector<int>& prices) {
        
        // since we can hold one stock so therefore we store it in a variable whether we can buy or not
        int n=prices.size();
        return solve_tab(n,prices);
    }
};