class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int bought=INT_MAX;
        int sell=0;
        int n=prices.size();
        int maxprofit=0;
        for(int i=0;i<n;i++){
            if(prices[i] < bought ){
           bought=min(bought, prices[i]);
            }
         
           maxprofit = max(maxprofit, prices[i] - bought);

        }
        return maxprofit;
    }
};