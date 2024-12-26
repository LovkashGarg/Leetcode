class Solution {
public:
    int solve(vector<int>& nums, int sum, int i,vector<vector<int>>& dp) {


        if(i < 0) {
            if(sum == 0)
                return 1;
            return 0;
        }
        
        if(dp[i][sum] !=-1 ){
            // cout<<" hello"<<endl;
            return dp[i][sum];
        }

        
        // simple include exclude 
        // total after next values 

        // excluded this element 
        int exclude = solve(nums, sum, i - 1,dp);
        int include = 0;
        
        // if the target i.e sum is greater than nums[i ] then only subtract 
        if(sum >= nums[i])
            include = solve(nums, sum - nums[i], i - 1,dp);

        return dp[i][sum] =include + exclude;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();   
        int sum = 0;
        
        // here calculated the sum 
        for(auto &it : nums)
            sum += it;

        if((sum - target) % 2 != 0 || (sum - target) < 0)
            return 0;
        
        
        target = sum - target;
       vector<vector<int>>dp(n, vector<int>(target + 1, -1));
        // checked if the s1 
        
        return solve(nums,target/2, n - 1,dp);
    }
};