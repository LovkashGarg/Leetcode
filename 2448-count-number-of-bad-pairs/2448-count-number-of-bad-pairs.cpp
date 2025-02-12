class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
         map<int,int>m;
         int n=nums.size();
         long long countnotbad=0;
         for(int i=0;i<n;i++){
            
             if(m.find(nums[i]-i)!= m.end() ){
             countnotbad+=m[nums[i]-i];
             }

             m[nums[i]-i]++; // store this 

         }
         long long total = 1ll* (n)*(n-1)/2; // unique pairs 
         return total- countnotbad;
    }
};