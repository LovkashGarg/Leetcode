class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long long low=0;
        long long high=sqrt(c); // important 10 ^9 ka sqrt is 10 ^5 almost which is allowed

        while(low<=high){
            long long val= low * low + high*high;
           
            if(val==c){
                return true;
            }
            else if(val > c){
                high--;
            }
            else{
                low++;
            }
        }
        return false;

    }
};