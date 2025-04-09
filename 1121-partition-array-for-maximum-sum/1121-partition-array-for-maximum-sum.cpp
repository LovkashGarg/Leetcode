class Solution {
public:
   int solve(int index , int k , vector<int>&nums , int n ,vector<int>&dp ){

    if(index==n ){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }

    // so firstly 
    // total element is less then k 
    int maxsum=0;
    int maxi=INT_MIN;
    for(int i = index ;i<index + k && i<n;i++){
         maxi=max(maxi , nums[i]);
         maxsum=max(maxsum ,  maxi *(i-index+1) + solve(i+1,k,nums,n,dp));
    }

     return  dp[index]= maxsum;
   }
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
     
      int n= nums.size();
      vector<int>dp(n+1,-1);
     // I need firstly the maxvalue , k check if number of element is less , and total sum 
       return solve(0,k,nums,n,dp);
    }
};