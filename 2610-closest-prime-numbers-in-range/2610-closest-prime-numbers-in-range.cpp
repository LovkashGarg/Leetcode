class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        
        // first I have to find the prime number in a range then I have to check 
        vector<int>primes(1e6+7,1); // now all are prime 

        // now I have to check for all the primes 
        for(int i=2;i<=1e6;i++){
             if(primes[i]==1){
               for ( long long m = i*1ll* i; m <= 1e6; m += i){
                primes[m] = false;
               }
             }
        }

        // now here 
        vector<int>sieve;
        for(int i=2;i<=1e6;i++){
            if(primes[i]==true && i>=left && i<=right){
               sieve.push_back(i);
            }
            
        }
         int n=sieve.size();
         int minidiff=INT_MAX;
         vector<int>ans(2,-1);
        // total primes are very less 
         for(int i=0;i<n-1;i++){
          if(minidiff > (sieve[i+1]- sieve[i])){

                    minidiff=sieve[i+1]- sieve[i];
                    ans[0]=sieve[i];
                    ans[1]=sieve[i+1];
         }
         }
        return ans;

    }
};