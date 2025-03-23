class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0){
            return 1;
        }
        else if(n==1){
            return x;
        }
        else if(n>0){
            // even 
            double val= myPow(x,n/2);
           if(n%2==0){
             return val*val;
           }
           else{
            return x*val*val;
           }
        }
        // n is negative 
        else {
          double val= myPow(x, -(n/2));
          if(n%2==0){
            return double(1)/val* double(1)/val;
          }
          else{
             return (double(1)/x) *(double(1)/val)*(double(1)/val);
          }

        }

    }
};