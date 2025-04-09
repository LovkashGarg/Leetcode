class Solution {
public:

    int maxSumAfterPartitioning(vector<int>& nums, int k) {
     
      int n= nums.size();
      vector<int>dp(n+1,0);
      dp[n]=0;
      int maxsum =0;
      for(int i=n-1;i>=0;i--){
        int maxi=INT_MIN;
           for(int j=i;j<min(i+k,n) ;j++){
            maxi= max(maxi , nums[j]);
            maxsum = max(maxsum , maxi *(j-i+1) +  dp[j+1]);
           }
        dp[i]= maxsum;

      }

    return dp[0];

    }
};