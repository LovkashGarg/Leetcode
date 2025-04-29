class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

       int l=0;
       int r=0;
       int maxi=*max_element(nums.begin(), nums.end());
       int n= nums.size();
       int freq=0;
       long long count=0;


       while(r<n){
         if(nums[r]==maxi){
            freq++;
         }

         while(freq>=k){
          if(nums[l]==maxi){
            freq--;
          }
         count += (n - r);
          l++;
         }

         r++;
       }

       return count;
    }
};