class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
         ios_base::sync_with_stdio(false);
          cin.tie(NULL);
        int n=prices.size();

       vector<int>discount(n,0);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    discount[i]=prices[j];
                    break;
                }
            }
        }

        for(int i=0;i<n;i++){
            prices[i]=prices[i]-discount[i];
        }
        return prices;
    }
};