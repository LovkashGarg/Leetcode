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

       
         int low=0;
         int high=n-1;
         while(low<=high){
           
            if(nums[low]+ nums[high] <=target){
                ans= (ans %mod + power[high-low])%mod;
                low++;
            }
            else{
                high--;
            }
         }

     

       return ans;
    }
};