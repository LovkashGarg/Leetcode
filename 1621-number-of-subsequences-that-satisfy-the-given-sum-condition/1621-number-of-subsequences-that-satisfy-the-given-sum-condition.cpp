class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       long long ans=0;
       long long mod=1e9 +7;
int n= nums.size();
// Precompute powers of 2 modulo mod
        vector<long long> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }

       for(int i=0;i<n;i++){
         int low=i;
         int high=n-1;
         long long indexes=-1;
         while(low<=high){
            int mid= (low + high)/2;
            if(nums[i]+ nums[mid] <=target){
                low = mid+1;
                indexes=mid-i;
            }
            else{
                high= mid-1;
            }
         }

         // now find the total number of subsequence that can be formed between them 
        if (indexes >= 0) {
             ans = (ans + power[indexes]) % mod;
        }

       } 

       return ans;
    }
};