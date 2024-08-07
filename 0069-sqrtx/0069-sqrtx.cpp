class Solution {
public:
    int mySqrt(int x) {
        long long int i=0;
        long long int j=x;
        long long int d=i*i;
       while(d<=j){
        i++;
        d=i*i;
       }
       return i-1;
    }
};