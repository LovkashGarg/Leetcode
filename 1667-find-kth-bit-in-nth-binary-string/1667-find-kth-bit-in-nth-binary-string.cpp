class Solution {
public:
string d="011";
    char findKthBit(int n, int k) {
        
        if(n==1){
            return '0';
        }

        int len = pow(2, n) - 1; // for n=3 length is 7 
        

        if(k-1==len/2){
            return '1'; 
        }
        else if(k-1<len/2){
           // means on left side 
           return findKthBit(n-1,k);
        }
        else{
            char val= findKthBit(n-1,len-k+1);
            if(val=='0'){
                return '1';
            }
            return '0';
        }
    }
};