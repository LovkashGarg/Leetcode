class Solution {
public:
    int mySqrt(int x) {
        int low =0;
        int high=x;
        while(low<=high){
         long long int mid=low + (high-low)/2;
         long long square=mid*mid;
         if(square>x){
            high=mid-1;
         }
         else if(square==x){
            return mid;
         }
         else{
            low=mid+1;
         }
        }

       return high;
    }
};