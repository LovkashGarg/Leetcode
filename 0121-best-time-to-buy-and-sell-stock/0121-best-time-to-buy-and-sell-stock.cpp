class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // here first I can store the min buying price and then subtract 

        int n=prices.size();
        vector<int>minbought(n,INT_MAX);
        int maxprofit=0;
        minbought[0]= prices[0];
        for(int i=1;i<n;i++){
          minbought[i]=min(minbought[i-1], prices[i]);
          if(prices[i] > minbought[i-1]){
            maxprofit=max(maxprofit,prices[i]-minbought[i-1] );
          }
        }

        return maxprofit;
    }
};