class Solution {
public:
    int kthGrammar(int n, int k) {
        
        int len=pow(2,n-1); 
        // for n==1 lenth is 1 
        // for n==2 length is 2
        if(n==1){
            return 0;
        }
       
        if(k-1 < (len/2)){
            return kthGrammar(n-1,k);
        }
        else{
            // maintain 1 index 
            int val=kthGrammar(n-1, k- (len/2));
            if(val==0){
                return 1;
            }
            return 0;
        }
    }
};