class Solution {
public:
    int solve(vector<int>&nums,int start,int n, vector<int>&dp){

        if(start >=n){
            return 0;
        }
        if(dp[start]!=-1){
            return dp[start];
        }

        int include =  nums[start] + solve(nums, start+2, n, dp);
        int exclude = solve(nums, start+1, n, dp);
        return dp[start]= max(include , exclude);
    }
    int rob(vector<int>& nums) {
 
        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(solve(nums,0,n-1,dp1) ,solve(nums,1,n,dp2)  )  ;

    }
};