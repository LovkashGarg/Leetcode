class Solution {
public:
    int arrangeCoins(int n) {
        
        int low=0;
        long long high=n;
        while(low<=high){
            long long mid= (low)+ (high-low)/2;

            if(n>= (mid)*(mid+1)/2){
                // matlab todi kam fill kari hai mene
                low=mid+1;
          
            }
            else{
                   high=mid-1;
            }
        }
        return low-1;
    }
};