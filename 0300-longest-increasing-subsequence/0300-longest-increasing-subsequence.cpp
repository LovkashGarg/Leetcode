class Solution {
public:
   int solve(int prev, int curr, int n, vector<int> & nums, vector<vector<int>>&dp){
    if(curr>=n){
        return 0;
    }

    if(dp[prev+1][curr]!=-1){
        return dp[prev+1][curr];
    }


    // include or exclude 
    int first=0;
    int second=0;
    if(prev==-1){
    first = 1+ solve(curr,curr+1,n,nums,dp);
    }
    else{
        if(nums[prev]<nums[curr]){
            second = 1+ solve(curr, curr+1,n,nums,dp);
        }
    }

    int third= solve(prev,curr+1,n, nums,dp);

    return dp[prev+1][curr]= max(first, max(second,third));

   }
    int lengthOfLIS(vector<int>& nums) {
         int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(-1,0, n, nums,dp);
    }
};