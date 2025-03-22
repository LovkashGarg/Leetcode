class Solution {
public:
    bool solve(int index, vector<int> & nums,vector<int>&dp,int n ){

     if(index >=n-1){
        return  1;
     } 
     if(dp[index] !=-1){
        return dp[index];
     }

     int steps= nums[index];

     for(int i=index+1;i<=index + steps;i++){
         if(solve(i , nums,dp,n)){
            return dp[index]=1;
         }
    }

    return dp[index]=0;

    }
    bool canJump(vector<int>& nums) {
        
       int n= nums.size();
       vector<int>dp(n,-1);
       return solve(0,nums,dp,n);

    }
};