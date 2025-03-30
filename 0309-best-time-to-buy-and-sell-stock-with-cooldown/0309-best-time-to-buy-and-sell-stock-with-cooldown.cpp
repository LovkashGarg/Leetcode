class Solution {
public:
    int maxProfit(vector<int>& prices) {
int n=prices.size();

       vector<int>curr(2,0);
       vector<int>next(2,0);
       vector<int>fornext(2,0);

       for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy==0){
               curr[buy]= max(-prices[i] + next[1] , next[0]);
            }
            else{
                // since cant buy on next day 
                curr[buy]= max(prices[i] + fornext[0] , next[1]);
            }
        }

        fornext=next;
        next=curr;
       }

       return next[0];

    }
};