class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int boughtfor=prices[0];
        int maxsellfor=prices[0];
        int profit=0;
        for(int i=1;i< prices.size();i++){
            if(boughtfor > prices[i]){
               profit+= ( maxsellfor - boughtfor);
               maxsellfor=prices[i];
               boughtfor=prices[i];
            }else if(maxsellfor > prices[i]){
                 profit+= ( maxsellfor - boughtfor);
                 boughtfor= prices[i];
                 maxsellfor=prices[i];
            }
            maxsellfor= max(maxsellfor, prices[i]);
        }
         profit+= ( maxsellfor - boughtfor);
         return profit;

    }
};