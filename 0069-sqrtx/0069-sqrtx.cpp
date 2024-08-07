class Solution {
public:
    int mySqrt(int x) {
        long long int i=0;
        long long int j=x;
       while((i*i)<=j){
        i++;
       }
       return i-1;
    }
};